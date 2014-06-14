#include <boost/python.hpp>
#include <boost/python/object.hpp>
#include "somelib/SomeReader.h"
#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/stream_buffer.hpp>
#include <stdexcept>


using namespace boost::python;

namespace io = boost::iostreams;

struct SomeReaderWrap: SomeReader, wrapper<SomeReader>
{
    bool read(object &py_file)
    {
        if (PyFile_Check(py_file.ptr()))
        {
            FILE* handle = PyFile_AsFile(py_file.ptr());
            io::stream_buffer<io::file_descriptor_source> fpstream (fileno(handle), io::never_close_handle);
            std::istream in(&fpstream);
            return this->read_from_stream(in);
        }
        else
        {
            //
            // How do we implement this
            //
            throw std::runtime_error("Not a file, have no idea how to read this!");
        }
    }
};


BOOST_PYTHON_MODULE(somelib)
{
    class_<SomeReaderWrap, boost::noncopyable>("SomeReader")
        .def("read", &SomeReaderWrap::read);
}
