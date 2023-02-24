#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "lwip/err.h"
#include "lwip/sys.h"
#include <esp_http_server.h>
// SSID tidak perlu diubah, jika ingin mengubah, sebaiknya jangan mengubah menjadi ssid yang sama dengan yang sudah ada pada jangkauan.

#define EXAMPLE_ESP_WIFI_SSID "for_robot"
#define EXAMPLE_ESP_WIFI_PASS "qwertyuiop123"
#define EXAMPLE_ESP_WIFI_CHANNEL 1
#define EXAMPLE_MAX_STA_CONN 4
#define LED_PIN 22
#define GPIO_OUTPUT_PIN_SEL (1ULL<<LED_PIN)
static const char* TAG_WIFI = "wifi softAP";
static const char* TAG_SERVER = "webserver";
static void wifi_event_handler(void* arg, esp_event_base_t event_base,
    int32_t event_id, void* event_data) {
        if (event_id == WIFI_EVENT_AP_STACONNECTED) {
            wifi_event_ap_staconnected_t* event =
            (wifi_event_ap_staconnected_t*)event_data;
            ESP_LOGI(TAG_WIFI, "station "MACSTR" join, AID=%d",
            MAC2STR(event->mac), event->aid);
        } else if (event_id == WIFI_EVENT_AP_STADISCONNECTED) {
            wifi_event_ap_stadisconnected_t* event =
            (wifi_event_ap_stadisconnected_t*)event_data;
            ESP_LOGI(TAG_WIFI, "station "MACSTR" leave, AID=%d",
            MAC2STR(event->mac), event->aid);
        }
    }

void wifi_init_softap(void) {
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_create_default_wifi_ap();
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,
    ESP_EVENT_ANY_ID,
    &wifi_event_handler,
    NULL,
    NULL));
    wifi_config_t wifi_config = {
        .ap = {
            .ssid = EXAMPLE_ESP_WIFI_SSID,
            .ssid_len = strlen(EXAMPLE_ESP_WIFI_SSID),
            .channel = EXAMPLE_ESP_WIFI_CHANNEL,
            .password = EXAMPLE_ESP_WIFI_PASS,
            .max_connection = EXAMPLE_MAX_STA_CONN,
            .authmode = WIFI_AUTH_WPA_WPA2_PSK
        },
    };

    if (strlen(EXAMPLE_ESP_WIFI_PASS) == 0) {
        wifi_config.ap.authmode = WIFI_AUTH_OPEN;
    }
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_AP));
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_AP, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());
    ESP_LOGI(TAG_WIFI, "wifi_init_softap finished. SSID:%s password:%s channel:%d",EXAMPLE_ESP_WIFI_SSID, EXAMPLE_ESP_WIFI_PASS,EXAMPLE_ESP_WIFI_CHANNEL);
}
static esp_err_t hello_get_handler(httpd_req_t* req) {
    char* buf;
    size_t buf_len;
    buf_len = httpd_req_get_hdr_value_len(req, "Host") + 1;
    if (buf_len > 1) {
        buf = malloc(buf_len);
        if (httpd_req_get_hdr_value_str(req, "Host", buf, buf_len) ==ESP_OK) {
            ESP_LOGI(TAG_SERVER, "Found header => Host: %s", buf);
        }
        free(buf);
    }
    buf_len = httpd_req_get_hdr_value_len(req, "Test-Header-2") +1;
    if (buf_len > 1) {
        buf = malloc(buf_len);
        if (httpd_req_get_hdr_value_str(req, "Test-Header-2", buf, buf_len) == ESP_OK) {
            ESP_LOGI(TAG_SERVER, "Found header => Test-Header-2: %s", buf);
        }
        free(buf);
    }
    buf_len = httpd_req_get_hdr_value_len(req, "Test-Header-1") +1;
    if (buf_len > 1) {
        buf = malloc(buf_len);
        if (httpd_req_get_hdr_value_str(req, "Test-Header-1", buf,buf_len) == ESP_OK) {
            ESP_LOGI(TAG_SERVER, "Found header => Test-Header-1: %s",buf);
        }
        free(buf);
    }
    buf_len = httpd_req_get_url_query_len(req) + 1;
    if (buf_len > 1) {
        buf = malloc(buf_len);
        if (httpd_req_get_url_query_str(req, buf, buf_len) == ESP_OK){
            ESP_LOGI(TAG_SERVER, "Found URL query => %s", buf);
            if (strcmp(buf, "on") == 0) {
                gpio_set_level(LED_PIN, 1);
            } else {
                gpio_set_level(LED_PIN, 0);
            }
            char param[32];
            if (httpd_query_key_value(buf, "query1", param, sizeof(param)) == ESP_OK) {
                ESP_LOGI(TAG_SERVER, "Found URL query parameter => query1=%s", param);
            }
            if (httpd_query_key_value(buf, "query3", param,sizeof(param)) == ESP_OK) {
                ESP_LOGI(TAG_SERVER, "Found URL query parameter => query3=%s", param);
            }
            if (httpd_query_key_value(buf, "query2", param,sizeof(param)) == ESP_OK) {
                ESP_LOGI(TAG_SERVER, "Found URL query parameter => query2=%s", param);
            }
        }
        free(buf);
    }  
    httpd_resp_set_hdr(req, "Custom-Header-1", "Custom-Value-1");
    httpd_resp_set_hdr(req, "Custom-Header-2", "Custom-Value-2");
    const char* resp_str = (const char*)req->user_ctx;
    httpd_resp_send(req, resp_str, strlen(resp_str));
    if (httpd_req_get_hdr_value_len(req, "Host") == 0) {
        ESP_LOGI(TAG_SERVER, "Request headers lost");
    }
    return ESP_OK;
}
static const httpd_uri_t hello = {
    .uri = "/",
    .method = HTTP_GET,
    .handler = hello_get_handler,
    .user_ctx = "<!DOCTYPE html><html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"><link rel=\"icon\" href=\"data:,\"><style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}.button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}.button2 {background-color: #555555;}</style></head><body><h1>ESP32 Web Server</h1><p><a href=\"?on\"><button class=\"button\">ON</button></a></p><p><a href=\"?off\"><button class=\"button button2\">OFF</button></a></p>"
    };
esp_err_t http_404_error_handler(httpd_req_t* req,httpd_err_code_t err) {
    if (strcmp("/", req->uri) == 0) {
        httpd_resp_send_err(req, HTTPD_404_NOT_FOUND, "/ URI is not available");
        return ESP_OK;
    }
    httpd_resp_send_err(req, HTTPD_404_NOT_FOUND, "Some 404 error message");
    return ESP_FAIL;
}
static httpd_handle_t start_webserver(void) {
    httpd_handle_t server = NULL;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    ESP_LOGI(TAG_SERVER, "Starting server on port: '%d'", config.server_port);
    if (httpd_start(&server, &config) == ESP_OK) {
        ESP_LOGI(TAG_SERVER, "Registering URI handlers");
        httpd_register_uri_handler(server, &hello);
        return server;
    }
    ESP_LOGI(TAG_SERVER, "Error starting server!");
    return NULL;
}
void app_main(void) {
    // jangan lupa diisi
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_POSEDGE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_config(&io_conf);
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
    ESP_LOGI(TAG_WIFI, "ESP_WIFI_MODE_AP");
    wifi_init_softap();
    static httpd_handle_t server = NULL;
    server = start_webserver();
}


