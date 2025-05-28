# MESSAGES ORIENTED MIDDLEWARE

In this poject we're presenting an entire architecture with an API rest, a cluster of MOM's and some clients. 

The idea is that the clients will
- create and delete topics 
- create and delete queues
- create and delete messages inside each structure

## How to run the project 
### API REST

**UNIX** Go inside `rest_API` and run the following command
```console 
    rm -rf build/;mkdir build; cd build; cmake ..;make;./mom
```

**WINDOWS** Go inside `rest_API` and run the following command
```console 
    Remove-Item -Recurse -Force build; New-Item -ItemType Directory -Path build; Set-Location -Path build; cmake ..; make; ./mom
```
After this your endpoints should be running


### MOM


**UNIX** Go inside `mom_communication` and run the following command
```console 
    rm -rf build/;mkdir build; cd build; cmake ..;make
```

**WINDOWS** Go inside `rest_API` and run the following command
```console 
    Remove-Item -Recurse -Force build; New-Item -ItemType Directory -Path build; Set-Location -Path build; cmake ..; make; ./mom
```
> you should clone, compile and link the grpc library, for this project we used the v1.71.0

## Related links 
- **Build gRPC with Cmake** - https://github.com/grpc/grpc/blob/v1.71.0/BUILDING.md

- **Download crow** - https://crowcpp.org/master/getting_started/setup/linux/

- **gRPC DOCS** - https://grpc.io/docs/languages/cpp/basics/
