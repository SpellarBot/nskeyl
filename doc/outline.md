

# The data flow

### nskeyld
1. injest raw network events in nskeyld
2. filter out unimportant info, and put info we want to keep in an in memory queue of `struct node_diffs`
3. clients subscribe to nskeyld using an HTTP GET websocket interface and receive a list of JSON `node_diff` objects
    - HTTP GET params specify filter parameters, only return to client `node_diff` objects that satisfy the requested filter

4. translate `node_diffs` into postgres create/update operations and send to postgres to keep track of all historical node data

### nskeyls
1. filter parameters are supplied from commandline arguments
2. connect to the nskeyld daemon using HTTP GET websocket request with filter parameters
3. print all received `node_diffs` to stdout


### nskeylh
1. receive HTTP GET batch requests with filter parameters from nskeylb, translate this to postgres SELECT queries
2. return HTTP GET response as list of JSON `node` objects

### nskeylb
1. get filter params from commandline arguments
2. make HTTP GET request to nskeylh
3. print JSON `node` objects to stdout