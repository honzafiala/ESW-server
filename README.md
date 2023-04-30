# Compile proto files
protoc -I=src/ --cpp_out=src/ /proto/measurements.proto 

# Run server
builddir/src/main PORT_NUM