#include "queue_list.h"
#include "queue_obj.h"


/*  In this method using the QUEUE_OBJ object,
    we check if there is another queue with the
    same name. If there is, we return an error.
    Otherwise, we add the object to the 
    list of queues.
*/
int queue_list::add_queue_to_list(queue_obj queue){
    for(queue_obj queue_in_list:queue_list){
        if (queue_in_list.get_queue_name() == queue.get_queue_name()){
            cout<<"there is already a queue with this name"<<endl;
            return -1;
        }
    }
    this->queue_list.push_back(queue);
    return 0;
}


/*  In this method, we do something similar to 
    the previous one, but to increase security,
    we check whether the user who sent the
    request is the same one who created the queue.
*/
int queue_list::delete_queue_from_list(string queue_to_delete,string owner_queue_to_delete){
    for (int i = 0; i < queue_list.size(); i++) {
        cout<<queue_list[i].get_queue_name() << queue_to_delete;
        if (queue_list[i].get_queue_name() == queue_to_delete && queue_list[i].get_queue_owner() == owner_queue_to_delete ){
            this->queue_list.erase(queue_list.begin()+i);
            return 0;
        }
      }
    return -1;
}


vector<queue_obj> queue_list::get_queue_list(){return this->queue_list;}



queue_obj* queue_list::get_specific_queue(string name_queue_to_get, string owner_queue_to_get){
    for(queue_obj& queue_in_list:queue_list){ 
        if (queue_in_list.get_queue_name() == name_queue_to_get && queue_in_list.get_queue_owner() == owner_queue_to_get ){
            return &queue_in_list; 
        }
    }
    return nullptr;

}    