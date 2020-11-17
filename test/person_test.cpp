//
// Created by bdmendes on 27/10/20.
//

#include <gtest/gtest.h>
#include "model/person/person.h"
#include "model/person/client/client.h"
#include "model/person/worker/worker.h"

using testing::Eq;

/*TEST(Person, create_person){
    Person person1("Joel Lopes", 184932019, {"joel_lopes123", "Lopes_123"});
    Credential credential = {"joel_lopes123", "Lopes_123"};

    EXPECT_EQ("Joel Lopes", person1.getName());
    EXPECT_EQ(184932019, person1.getTaxId());
    EXPECT_EQ(credential, person1.getCredential());

    Person person2("Manuela Rodrigues", 285931384, {"manuelaRodrigues", "9281manuela"});
    credential = {"manuelaRodrigues", "9281manuela"};

    EXPECT_EQ("Manuela Rodrigues", person2.getName());
    EXPECT_EQ(285931384, person2.getTaxId());
    EXPECT_EQ(credential, person2.getCredential());
}*/

TEST(Client, create_client){
    Client client1("Manuel Martins");
    Credential credential = {"client", "client"};

    EXPECT_EQ("Manuel Martins", client1.getName());
    EXPECT_EQ(999999999, client1.getTaxId());
    EXPECT_EQ("client", client1.getCredential().username);
    EXPECT_EQ("client", client1.getCredential().password);
    EXPECT_FLOAT_EQ(0, client1.getPoints());
    EXPECT_FALSE(client1.isPremium());
    EXPECT_FLOAT_EQ(0, client1.getPoints());

    Client client2("Angelica Vieira", true, 287389139, {"AngelicaVieira", "Angelica_8293"});
    credential = {"AngelicaVieira", "Angelica_8293"};

    EXPECT_EQ("Angelica Vieira", client2.getName());
    EXPECT_EQ(287389139, client2.getTaxId());
    EXPECT_EQ("AngelicaVieira", client2.getCredential().username);
    EXPECT_EQ("Angelica_8293", client2.getCredential().password);
    EXPECT_FLOAT_EQ(0, client2.getPoints());
    EXPECT_TRUE(client2.isPremium());
    EXPECT_FLOAT_EQ(0, client2.getPoints());
}

TEST(Worker, create_worker){
    Worker worker1("Joao Filipe", 950);
    Credential credential = {"worker", "worker"};

    EXPECT_EQ("Joao Filipe", worker1.getName());
    EXPECT_FLOAT_EQ(950, worker1.getSalary());
    EXPECT_EQ(999999999, worker1.getTaxId());
    EXPECT_EQ("worker", worker1.getCredential().username);
    EXPECT_EQ("worker", worker1.getCredential().password);
    //EXPECT_EQ(0, worker1.getOrders());
    EXPECT_TRUE(worker1.getCredential() == credential);
    EXPECT_FLOAT_EQ(950, worker1.getSalary());

    Worker worker2("Filipa Ribeiro", 893, 293013289, {"FilipaRibeiro","filipaRibeiro_9201"});
    credential = {"FilipaRibeiro", "filipaRibeiro_9201"};

    EXPECT_EQ("Filipa Ribeiro", worker2.getName());
    EXPECT_FLOAT_EQ(893,worker2.getSalary());
    EXPECT_EQ(293013289, worker2.getTaxId());
    EXPECT_EQ("FilipaRibeiro", worker2.getCredential().username);
    EXPECT_EQ("filipaRibeiro_9201", worker2.getCredential().password);
    //EXPECT_EQ(0, worker2.getOrders());
    EXPECT_TRUE(worker2.getCredential() == credential);
    EXPECT_FLOAT_EQ(893,worker2.getSalary());
}

/*TEST(Person, change_name){
    Person person("Miguel Oliveira", 184932981, {"miguelO", "mig123_1"});
    person.setName("Miguel Ribeiro");

    EXPECT_EQ("Miguel Ribeiro", person.getName());
    EXPECT_THROW(person.setName("Miguel Ribeiro"), InvalidPersonNameChange);

    Client client("Ricardo Silva");
    client.setName("Ricardo Gomes");

    EXPECT_EQ("Ricardo Gomes", client.getName());
    EXPECT_THROW(client.setName("Ricardo Gomes"), InvalidPersonNameChange);

    client.setName("Filipe Gomes");

    EXPECT_EQ("Filipe Gomes", client.getName());

    Worker worker("Maria Rodrigues", 790);
    worker.setName("Sandra Rodrigues");

    EXPECT_EQ("Sandra Rodrigues", worker.getName());
    EXPECT_THROW(worker.setName("Sandra Rodrigues"), InvalidPersonNameChange);

    worker.setName("Sandra Silva");

    EXPECT_EQ("Sandra Silva", worker.getName());
}*/

/*TEST(Person, change_credential){
    Person person("Olga Machado", 284913847, {"machado_olga", "olga123"});
    Credential personCredential = {"machado_olga", "OlgaMachado_341"};
    person.setCredential(personCredential);

    EXPECT_TRUE(person.getCredential() == personCredential);
    EXPECT_THROW(person.setCredential(personCredential), InvalidPersonCredentialChange);

    Client client("Rui Macedo");
    Credential clientCredential = {"Ruimacedo", "macedo@123"};
    client.setCredential(clientCredential);

    EXPECT_TRUE(client.getCredential() == clientCredential);
    EXPECT_THROW(client.setCredential(clientCredential), InvalidPersonCredentialChange);

    clientCredential.username = "ruimacedo";
    client.setCredential(clientCredential);

    EXPECT_TRUE(client.getCredential() == clientCredential);

    Worker worker("Luis Figo", 920);
    Credential workerCredential = {"figoLuis13", "921-figo"};
    worker.setCredential(workerCredential);

    EXPECT_TRUE(worker.getCredential() == workerCredential);
    EXPECT_THROW(worker.setCredential(workerCredential), InvalidPersonCredentialChange);

    workerCredential.password = "senha321";
    worker.setCredential(workerCredential);

    EXPECT_TRUE(worker.getCredential() == workerCredential);
}

TEST(Person, sort_people){
    Person person1("Joao Ricardo", 285742345, {"joao", "1234"});
    Person person2("Ana Maria", 294306748, {"anaMaria", "ana_123"});
    Person person3("Agostinho Lima", 213854059, {"gusto", "gusto1948"});

    EXPECT_TRUE(person2 < person1);
    EXPECT_TRUE(person3 < person1);
    EXPECT_FALSE( person2 < person3);

    Client client1("Beatriz Duarte");
    Client client2("Joana Fernandes");
    Client client3("Joao Martins");

    EXPECT_TRUE(client1 < client2);
    EXPECT_TRUE(client2 < client3);
    EXPECT_FALSE(client3 < client1);

    Worker worker1("Cristina Martins", 938);
    Worker worker2("Sara Ribeiro", 839);
    Worker worker3("Sara Couto", 940);

    EXPECT_TRUE(worker1 < worker2);
    EXPECT_TRUE(worker3 < worker2);
    EXPECT_FALSE(worker3 < worker1);

    EXPECT_TRUE(client1 < person1);
    EXPECT_TRUE(worker1 < person1);
    EXPECT_TRUE(person2 < client2);
    EXPECT_TRUE(person2 < worker2);
    EXPECT_TRUE(person3 < client3);
    EXPECT_TRUE(person3 < worker3);
}

TEST(Person, equal_person){
    Person person1("Joao Manuel", 284917316, {"jonasManel", "joao123"});
    Person person2("Joao Manuel", 284917316, {"joaoMan", "joao_m123"});
    Person person3("Joao Macedo", 183746173, {"joaom", "jonas_38"});

    EXPECT_TRUE(person1 == person2);
    EXPECT_FALSE(person1 == person3);
    EXPECT_FALSE(person2 == person3);
}*/

TEST(Client, equal_clients){
    Client client1("Cristina Lopes");
    Client client2("Cristina Lopes", false, 999999999, {"client", "client"});
    Client client3("Cristina Figueiredo");
    Client client4("Joao Manuel", false, 284917316, {"jonasManel", "joao123"});

    EXPECT_TRUE(client1==client2);
    EXPECT_FALSE(client1==client3);
    EXPECT_FALSE(client2==client3);
}

TEST(Worker, equal_workers){
    Worker worker1("Luis Miguel", 950);
    Worker worker2("Luis Miguel", 950, 999999999, {"worker", "worker"});
    Worker worker3("Luis Filipe", 890);
    Worker worker4("Joao Manuel", 950, 284917316, {"jonasManel", "joao123"});

    EXPECT_TRUE(worker1==worker2);
    EXPECT_FALSE(worker1==worker3);
    EXPECT_FALSE(worker2==worker3);
}

TEST(Client, set_premium){
    Client client("Joel Lopes", true);
    client.setPremium(false);

    EXPECT_FALSE(client.isPremium());

    client.setPremium(true);

    EXPECT_TRUE(client.isPremium());
}

TEST(Client, add_points){
    Client client("Joao Manuel");
    client.addPoints(50);

    EXPECT_EQ(50, client.getPoints());

    client.addPoints(18);

    EXPECT_EQ(68, client.getPoints());
}

TEST(Client, remove_points){
    Client client("Marta Fonseca");
    client.addPoints(43);
    client.removePoints(3);

    EXPECT_EQ(40, client.getPoints());

    client.addPoints(17); //Points = 57
    client.removePoints(10);

    EXPECT_EQ(47, client.getPoints());
}

TEST(Client, reset_poinst){
    Client client("Fabio Fernandes");
    client.addPoints(26);
    client.removePoints(13);
    client.resetPoints();

    EXPECT_EQ(0, client.getPoints());
}

//Note that evaluations are going to be validated in class Order
/*TEST(Client, add_evaluation){
    Client client("Jose Manuel");
    client.addEvaluation(3.7);
    client.addEvaluation(2.9);

    std::vector<float> evaluations = {3.7, 2.9};

    EXPECT_EQ(evaluations, client.getEvaluations());

    client.addEvaluation(4.5);
    evaluations.push_back(4.5);

    EXPECT_EQ(evaluations, client.getEvaluations());
}*/

/*TEST(Client, get_mean_evaluation){
    Client client("Joao Lima");
    client.addEvaluation(3.5);
    client.addEvaluation(2.7);

    EXPECT_FLOAT_EQ((3.5+2.7)/2, client.getMeanEvaluation());

    client.addEvaluation(4.73);
    client.addEvaluation(3.3);

    EXPECT_FLOAT_EQ((3.5+2.7+4.73+3.3)/4, client.getMeanEvaluation());
}*/

TEST(Worker, set_salary){
    Worker worker("Miguel Filipe", 830);
    worker.setSalary(920);

    EXPECT_FLOAT_EQ(920, worker.getSalary());

    worker.setSalary(892.3);

    EXPECT_FLOAT_EQ(892.3, worker.getSalary());
}

TEST(Worker, add_order){
    Worker worker("Afonso Duarte", 923);
    worker.addOrderToDeliver();
    worker.addOrderToDeliver();

    EXPECT_EQ(2, worker.getUndeliveredOrders());
}

TEST(Worker, remove_order){
    Worker worker("Rafael Simao", 872);
    worker.addOrderToDeliver();
    worker.addOrderToDeliver();
    worker.addOrderToDeliver();
    worker.removeOrderToDeliver();
    worker.removeOrderToDeliver();

    EXPECT_EQ(1, worker.getUndeliveredOrders());
}
