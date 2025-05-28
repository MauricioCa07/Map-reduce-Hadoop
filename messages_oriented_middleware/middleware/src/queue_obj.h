#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <ctime>
#include <map>


using namespace std;

class queue_obj {
private:
    string queue_name;
    string queue_owner;
    time_t creation_stamp;
    std::queue<string> message_queue;
    std::map<std::string, std::string> properties;

public:
    queue_obj(string name, string owner,map<string, string> properties);

    /* ---------------------------------------------------
        -                                                -
        -                    GETTERS                     -
        -                                                -
        --------------------------------------------------
    */

    string get_queue_name();

    string get_queue_owner();

    time_t get_creation_stamp();

    map<string,string> get_properties();
    
    int get_message_count();

    
    /* ---------------------------------------------------
        -                                                -
        -                    SETTERS                     -
        -                                                -
        --------------------------------------------------
    */
    void set_queue_name(string new_name);

    void set_properties(map<string,string> new_properties);

    


    void add_message(string message);

    void delete_message();

};
