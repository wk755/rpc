set(SRC_LIST calluserservice.cc ../user.pb.cc) # ../上一级目录
#set(SRC_LIST callfriendservice.cc ../friend.pb.cc)
add_executable(consumer ${SRC_LIST})
target_link_libraries(consumer mprpc protobuf)