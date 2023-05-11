protobuf_dep = dependency('protobuf')
  add_project_arguments('-O2',  language : 'cpp')
srcs = ['main.cpp', 'epollinstance.cpp', 'epollsocket.cpp', 'proto/messages.pb.cc', 'epollconn.cpp', 'epollfd.cpp', 'request.cpp', 'graph.cpp']
executable('main', srcs,
  dependencies: [protobuf_dep])
