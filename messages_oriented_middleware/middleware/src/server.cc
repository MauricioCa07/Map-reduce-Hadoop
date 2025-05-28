#include <grpcpp/grpcpp.h>
#include "/app/mom.grpc.pb.h"
#include "/app/mom.pb.h" 
#include "queue_list.h"
#include "queue_obj.h"
#include <string>

using grpc::ServerContext;
using grpc::Status;
using grpc::ServerBuilder;
using grpc::Server;



queue_list queues;



class mom_impl final : public mom::MOM_service::Service {
  public:

    /* ---------------------------------------------------
        -                                                -
        -              METHODS FOR SYNC MOMS             -
        -                                                -
        --------------------------------------------------
    */
      Status sync_topics(::grpc::ServerContext* context, const ::mom::NodeID* request, ::mom::sync_response* response)override{return Status::OK;}
      Status sync_queues(::grpc::ServerContext* context, const ::mom::NodeID* request, ::mom::sync_response* response)override{return Status::OK;}
      
      
    /* ---------------------------------------------------
        -                                                -
        -              QUEUE'S METHODS                   -
        -                                                -
        --------------------------------------------------
    */

      /*
        Here we create the queue, then we see if there is a 
        queue with the same name in the queue_list and if so 
        we delete the object we just created. 
      */
      Status create_queue(::grpc::ServerContext* context, const ::mom::queue_config* request, ::mom::status* response)override{
        string name = request->name();
        string owner = request->owner();

        map<string, string> properties;
        for (const auto& entry : request->properties()) {
            properties[entry.first] = entry.second;
        }
        queue_obj new_queue(name,owner,properties);
        if(queues.add_queue_to_list(new_queue) == 0){
            response->set_success(true);
            response->set_message("Queue added successfully");
            return ::grpc::Status::OK;
          }
          response->set_success(false);
          response->set_message("there was an error creating the queue");
          return Status(grpc::StatusCode::ABORTED,"");
      }


      /*
        In this method, we take the name of the queue and the 
        username. If the user is the one who created the queue,
         we simply delete the queue.
      */
      Status delete_queue(::grpc::ServerContext* context, const ::mom::queue_identifier* request, ::mom::status* response)override{
        std::string queue_name = request->name();
        std::string queue_owner = request->owner();
        if (queues.delete_queue_from_list(queue_name,queue_owner) == 0){
            response->set_success(true);
            response->set_message("Queue deleted successfully");
            return ::grpc::Status::OK;
        }
        response->set_success(false);
        response->set_message("This queue doesn't exits or you are not the owner");
        return Status(grpc::StatusCode::ABORTED,"");
      }


      Status list_queues(::grpc::ServerContext* context, const ::mom::NodeID* request, ::mom::queues_response* response)override{
        std::vector<queue_obj> queues_list = queues.get_queue_list();

        for (queue_obj queue_to_return : queues_list) {
            mom::queue* queue_proto = response->add_queues();
    
            queue_proto->set_name(queue_to_return.get_queue_name());
            queue_proto->set_owner(queue_to_return.get_queue_owner());
            queue_proto->set_creation_timestamp(queue_to_return.get_creation_stamp());
            queue_proto->set_message_count(queue_to_return.get_message_count()); 
    
            const std::map<std::string, std::string>& props = queue_to_return.get_properties();
            auto* map_proto = queue_proto->mutable_properties();
            for (const auto& pair : props) {
                (*map_proto)[pair.first] = pair.second;
            }
            
        }
        response->set_success(true);
        response->set_message("Queues listed successfully");
        return ::grpc::Status::OK;
      }

 
      Status get_queue_info(::grpc::ServerContext* context, const ::mom::queue_identifier* request, ::mom::queue* response)override{
        string queue_name = request->name();
        string queue_owner = request->owner();
    
        queue_obj* found_queue = queues.get_specific_queue(queue_name, queue_owner);
        if (found_queue != nullptr) {
            response->set_name(found_queue->get_queue_name());
            response->set_owner(found_queue->get_queue_owner());
            response->set_creation_timestamp(found_queue->get_creation_stamp());
            response->set_message_count(found_queue->get_message_count()); // Don't forget this one if you want to include it
    
            const std::map<std::string, std::string>& props = found_queue->get_properties();
    
            auto* map_proto = response->mutable_properties();
    
            for (const auto& pair : props) {
                (*map_proto)[pair.first] = pair.second;
            }
            return ::grpc::Status::OK;
        }
            return ::grpc::Status(::grpc::StatusCode::NOT_FOUND, "Queue not found");
    }
      
      
      
      
      
    /* ---------------------------------------------------
        -                                                -
        -              TOPIC'S METHODS                   -
        -                                                -
        --------------------------------------------------
    */
      Status create_topic(::grpc::ServerContext* context, const ::mom::topic_config* request, ::mom::status* response)override{
        
        
        
        
        
        
        return Status::OK;
      }
      Status delete_topic(::grpc::ServerContext* context, const ::mom::topic_identifier* request, ::mom::status* response)override{return Status::OK;}
      Status list_topics(::grpc::ServerContext* context, const ::mom::NodeID* request, ::mom::topics_response* response)override{return Status::OK;}
      Status get_topic_info(::grpc::ServerContext* context, const ::mom::topic_identifier* request, ::mom::Topic* response)override{return Status::OK;}
      Status subscribe_topic(::grpc::ServerContext* context, const ::mom::topic_subscription* request, ::mom::status* response)override{return Status::OK;}
      Status unsubscribe_topic(::grpc::ServerContext* context, const ::mom::topic_subscription* request, ::mom::status* response)override{return Status::OK;}
      
      
      
      
      
      
    /* ---------------------------------------------------
        -                                                -
        -                     MESSAGES                   -
        -                                                -
        -------------------------------------------------- 
    */
      Status send_queue_message(::grpc::ServerContext* context, const ::mom::queue_message* request, ::mom::message_status* response)override{return Status::OK;}
      Status receive_queue_message(::grpc::ServerContext* context, const ::mom::queue_identifier* request, ::mom::message* response)override{return Status::OK;}
      Status publish_topic_message(::grpc::ServerContext* context, const ::mom::TopicMessage* request, ::mom::message_status* response)override{return Status::OK;}
      Status receive_topic_message(::grpc::ServerContext* context, const ::mom::topic_subscription* request, ::mom::message* response)override{return Status::OK;}
      Status acknowledge_message(::grpc::ServerContext* context, const ::mom::message_identifier* request, ::mom::status* response)override{return Status::OK;}
      /* ---------------------------------------------------
        -                                                -
        -                     CLUSTER                    -
        -                                                -
        --------------------------------------------------
    */
      Status join_cluster(::grpc::ServerContext* context, const ::mom::node_info* request, ::mom::cluster_info* response)override{return Status::OK;}
      Status leave_cluster(::grpc::ServerContext* context, const ::mom::NodeID* request, ::mom::status* response)override{return Status::OK;}
      Status heartbeat(::grpc::ServerContext* context, const ::mom::NodeID* request, ::mom::status* response)override{return Status::OK;}
      Status get_cluster_state(::grpc::ServerContext* context, const ::mom::NodeID* request, ::mom::cluster_state* response)override{return Status::OK;}
};  


int main(){
  mom_impl service;
  ServerBuilder builder;
  std::string server_address("0.0.0.0:34500");
  builder.AddListeningPort(server_address,::grpc::InsecureServerCredentials());
  builder.RegisterService(&service);

  std::unique_ptr<Server> server(builder.BuildAndStart());

  server->Wait();
  return 0;
}