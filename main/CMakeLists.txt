set(component_srcs main.c ../proto-c/tcpRequest.pb-c.c)

idf_component_register(SRCS "tcpRequest.c" "IOC.c" "main.c" "tcpIp.c" "utils.c" "wifi.c" "cryptography.c" "${component_srcs}"

                        REQUIRES  nvs_flash wifi_provisioning protocomm esp_https_server driver protobuf-c

                        INCLUDE_DIRS "." "../include" "../proto-c")



