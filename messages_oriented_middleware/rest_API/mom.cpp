#include "crow.h"

int main(){
    crow::SimpleApp app; 


    
    /* --------------------------------------------------
       -                                                -
       -              ROUTES FOR AUTENTICATON           -
       -                                                -
       --------------------------------------------------
    */
    CROW_ROUTE(app, "/auth/login").methods("POST"_method)
    ([](const crow::request& req){
        return "Hello world";
    });


    CROW_ROUTE(app, "/auth/register").methods("POST"_method)
    ([](const crow::request& req){
        return "Hello world";
    });

    CROW_ROUTE(app, "/auth/logout`").methods("POST"_method)
    ([](const crow::request& req){
        return "Hello world";
    });



    /* ---------------------------------------------------
        -                                                -
        -           ROUTES FOR TOPICS MANAGEMENT         -
        -                                                -
        --------------------------------------------------
    */
    CROW_ROUTE(app, "/topics").methods("GET"_method,"POST"_method)
    ([](const crow::request& req){
        return "Hello world";
    });


    CROW_ROUTE(app, "/topics/{topicName}").methods("GET"_method,"DELETE"_method)
    ([](const crow::request& req){
        return "Hello world";
    });



    /* ---------------------------------------------------
        -                                                -
        -           ROUTES FOR TOPICS QUEUES             -
        -                                                -
        --------------------------------------------------
    */
    CROW_ROUTE(app, "/queues").methods("GET"_method,"POST"_method)
    ([](const crow::request& req){
        return "Hello world";
    });


    CROW_ROUTE(app, "/queues/{topicName}").methods("GET"_method,"DELETE"_method)
    ([](const crow::request& req){
        return "Hello world";
    });



    /* ---------------------------------------------------
        -                                                -
        -           ROUTES FOR MESSAGES                  -
        -                                                -
        --------------------------------------------------
    */
    CROW_ROUTE(app, "/topics/{topicName}/messages").methods("GET"_method,"POST"_method)
    ([](const crow::request& req){
        return "Hello world";
    });

    CROW_ROUTE(app, "/queues/{queueName}/messages").methods("GET"_method,"POST"_method)
    ([](const crow::request& req){
        return "Hello world";
    });


    CROW_ROUTE(app, "/messages/{messageId}/ack").methods("GET"_method,"POST"_method)
    ([](const crow::request& req){
        return "Hello world";
    });




    //set the port, set the app to run on multiple threads, and run the app
    app.port(18080).multithreaded().run();
}
