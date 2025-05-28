#include "queue_obj.h"

queue_obj::queue_obj(string name, string owner,map<string, string> properties) {
    this->queue_name = name;
    this->queue_owner = owner;
    time_t now;
    time(&now);
    this->creation_stamp = now;
    this->properties = properties;
}




    /* ---------------------------------------------------
        -                                                -
        -                    GETTERS                     -
        -                                                -
        --------------------------------------------------
    */
    string queue_obj::get_queue_name() {return this->queue_name;}

    string queue_obj::get_queue_owner() {return this->queue_owner;}

    time_t queue_obj::get_creation_stamp() {return this->creation_stamp;}

    map<string,string> queue_obj::get_properties(){return this->properties;}

    int queue_obj::get_message_count(){return message_queue.size();}





   /* ---------------------------------------------------
        -                                                -
        -                    SETTERS                     -
        -                                                -
        --------------------------------------------------
    */
    void queue_obj::set_queue_name(string new_name){this->queue_name =new_name;}

    void queue_obj::set_properties(map<string,string> new_properties){this->properties = new_properties;}









void queue_obj::add_message(string message) {
    this->message_queue.push(message);
}

void queue_obj::delete_message() {
    this->message_queue.pop();
}


