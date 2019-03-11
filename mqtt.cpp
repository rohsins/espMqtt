#include "mqtt.h"

#define URI "mqtt://hardware.wscada.net"
#define USERNAME "rts"
#define PASSWORD "rts"

static esp_mqtt_client_handle_t client;
static vector<string> TopicStore;

static esp_err_t mqtt_event_handler(esp_mqtt_event_handle_t event)
{
    switch (event->event_id) {
        case MQTT_EVENT_CONNECTED:
            break;
        case MQTT_EVENT_DISCONNECTED:
            break;
        case MQTT_EVENT_SUBSCRIBED:
            break;
        case MQTT_EVENT_UNSUBSCRIBED:
            break;
        case MQTT_EVENT_PUBLISHED:
            break;
        case MQTT_EVENT_DATA:
            break;
        case MQTT_EVENT_ERROR:
            break;
    }
    return ESP_OK;
}

Mqtt::Mqtt() {

}

void Mqtt::Init() {
    static esp_mqtt_client_config_t MqttConf;
    
    MqttConf.uri = URI;
    MqttConf.username = USERNAME;
    MqttConf.password = PASSWORD;
    MqttConf.event_handle = mqtt_event_handler;
    
    client = esp_mqtt_client_init(&MqttConf);
    esp_mqtt_client_start(client);
}

void Mqtt::Init(esp_mqtt_client_config_t MqttConfArg) {
    client = esp_mqtt_client_init(&MqttConfArg);
    esp_mqtt_client_start(client);
}

int Mqtt::Publish(const char * topic, char *payload, int length, int qos, int retain) {
    return esp_mqtt_client_publish(client, topic, payload, length, qos, retain);
}

esp_err_t Mqtt::Subscribe(const char *topic, int qos) {
    //TopicStore.push_back(topic);
    return esp_mqtt_client_subscribe(client, topic, qos);
}

esp_err_t Mqtt::Unsubscribe(const char *topic) {
    return esp_mqtt_client_unsubscribe(client, topic);
}

Mqtt::~Mqtt() {
    esp_mqtt_client_destroy(client);
}

vector<string> Mqtt::GetSubscribedTopic(void) {
    return TopicStore;
}
