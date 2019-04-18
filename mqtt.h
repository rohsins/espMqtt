#include "mqtt_client.h"
#include <string>
#include <vector>
#include "esp_system.h"

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_event_loop.h"
#include "esp_log.h"

using namespace std;

typedef void (*subscribeListener)(esp_mqtt_event_handle_t er);

class Mqtt {
    public:
        Mqtt();
        void Init();
        void Init(esp_mqtt_client_config_t MqttConfArg);
        void Connect();
        void Disconnect();
        int Publish(const char * topic, char *payload, int lenght, int qos, int retain);
        subscribeListener* Subscribe(const char *topic, int qos);
        esp_err_t Unsubscribe(const char *topic);
        vector<string> GetSubscribedTopic(void);
        ~Mqtt();
};
