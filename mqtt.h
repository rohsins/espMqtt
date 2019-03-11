#include "mqtt_client.h"
#include <string>
#include <vector>

using namespace std;

class Mqtt {
    public:
        Mqtt();
        void Init();
        void Init(esp_mqtt_client_config_t MqttConfArg);
        int Publish(const char * topic, char *payload, int lenght, int qos, int retain);
        esp_err_t Subscribe(const char *topic, int qos);
        esp_err_t Unsubscribe(const char *topic);
        vector<string> GetSubscribedTopic(void);
        ~Mqtt();
};
