
import io
from somelib import SomeReader

#Simple case, read from file
print ">>Pyhton: reading from file"
test_file = open('test_file.txt', mode='rb')
reader = SomeReader()
reader.read(test_file)

#Here I have a problem
print ">>Pyhton: reading from ByteIO"
buf = io.BytesIO("Hello Stack Owerflow")
reader.read(buf)