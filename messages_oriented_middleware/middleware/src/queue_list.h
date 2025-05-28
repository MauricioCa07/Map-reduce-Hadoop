#pragma once
#include <list>
#include "queue_obj.h" 
#include <vector>

class queue_list {
private:
    std::vector<queue_obj> queue_list;

public:
    int add_queue_to_list(queue_obj queue);
    int delete_queue_from_list(string queue_to_delete,string own_queue_to_delete);
    vector<queue_obj> get_queue_list();
    queue_obj* get_specific_queue(string name_queue_to_get, string owner_queue_to_get);
};

