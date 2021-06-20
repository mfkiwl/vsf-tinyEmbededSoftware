# CMakeLists head

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    port
    port/rtos

    vendor/lwip/net_al
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/ports/rtos/include
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/include
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/include/lwip

    vendor/plf/aic8800/src/arch
    vendor/plf/aic8800/src/arch/boot
    vendor/plf/aic8800/src/arch/ll
    vendor/plf/aic8800/src/arch/cmsis

    vendor/plf/aic8800/src/driver
    vendor/plf/aic8800/src/driver/common
    vendor/plf/aic8800/src/driver/reg
    vendor/plf/aic8800/src/driver/ipc
    vendor/plf/aic8800/src/driver/stdio_uart
    vendor/plf/aic8800/src/driver/iomux
    vendor/plf/aic8800/src/driver/dma
    vendor/plf/aic8800/src/driver/ticker
    vendor/plf/aic8800/src/driver/flash
    vendor/plf/aic8800/src/driver/pmic
    vendor/plf/aic8800/src/driver/sleep
    vendor/plf/aic8800/src/driver/aic1000lite_regs
    vendor/plf/aic8800/src/driver/sysctrl
    vendor/plf/aic8800/src/driver/asdma_mst
    vendor/plf/aic8800/src/driver/trng
    vendor/plf/aic8800/src/driver/time
    vendor/plf/aic8800/src/driver/bt

    vendor/modules/common/api
    vendor/modules/dbg/api

    vendor/wifi/fhost
    vendor/wifi/fhost/application
    vendor/wifi/wlan
    vendor/wifi/macif
)

target_link_libraries(${VSF_LIB_NAME} INTERFACE
    vendor/plf/aic8800/lib/libdrv_lite.a
    vendor/wifi/lib/libwifi.a
    vendor/wpa_supplicant/lib/libwpa.a
)

target_sources(${VSF_LIB_NAME} INTERFACE
    vendor/lwip/dhcps/dhcps.c
    vendor/lwip/net_al/net_al.c
    vendor/lwip/net_al/net_iperf_al.c
    vendor/lwip/net_al/net_tg_al.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/ports/rtos/sys_arch.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/api/api_lib.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/api/api_msg.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/api/err.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/api/netbuf.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/api/netdb.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/api/netifapi.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/api/sockets.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/api/tcpip.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/ipv4/autoip.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/ipv4/dhcp.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/ipv4/etharp.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/ipv4/icmp.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/ipv4/ip4.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/ipv4/ip4_addr.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/ipv4/ip4_frag.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/ipv6/dhcp6.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/ipv6/ethip6.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/ipv6/icmp6.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/ipv6/inet6.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/ipv6/ip6.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/ipv6/ip6_addr.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/ipv6/ip6_frag.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/ipv6/mld6.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/ipv6/nd6.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/def.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/dns.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/inet_chksum.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/init.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/ip.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/mem.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/memp.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/netif.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/pbuf.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/raw.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/stats.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/sys.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/tcp.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/tcp_in.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/tcp_out.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/timeouts.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/core/udp.c
    vendor/lwip/lwip-STABLE-2_0_2_RELEASE_VER/src/netif/ethernet.c

    vendor/modules/common/src/co_dlist.c
    vendor/modules/common/src/co_list.c
    vendor/modules/common/src/co_math.c
    vendor/modules/common/src/co_pool.c
    vendor/modules/common/src/co_ring.c

    vendor/modules/dbg/src/dbg.c
    vendor/modules/dbg/src/dbg_assert.c
    vendor/modules/dbg/src/dbg_print.c

    vendor/plf/aic8800/src/arch/ll/ll.c
    vendor/plf/aic8800/src/driver/flash/flash_api.c
    vendor/plf/aic8800/src/driver/gpio/gpio_api.c
    vendor/plf/aic8800/src/driver/sdmmc/sdmmc_api.c
    vendor/plf/aic8800/src/driver/stdio_uart/stdio_uart.c
    vendor/plf/aic8800/src/driver/ticker/lp_ticker.c
    vendor/plf/aic8800/src/driver/ticker/lp_ticker_api.c
    vendor/plf/aic8800/src/driver/ticker/ticker_api.c
    vendor/plf/aic8800/src/driver/ticker/us_ticker.c
    vendor/plf/aic8800/src/driver/ticker/us_ticker_api.c
    vendor/plf/aic8800/src/driver/time/time_api.c
    vendor/plf/aic8800/src/driver/trans/arm_bitreversal2.S
    vendor/plf/aic8800/src/driver/trans/arm_cfft_q15.c
    vendor/plf/aic8800/src/driver/trans/arm_cfft_radix4_q15.C
    vendor/plf/aic8800/src/driver/trng/trng_api.c
    vendor/plf/aic8800/src/driver/uart/uart1_api.c
    vendor/plf/aic8800/src/driver/uart/uart2_api.c
    vendor/plf/aic8800/src/driver/usb_host/hal_hcd.c
    vendor/plf/aic8800/src/driver/usb_host/hal_usbh.c
    vendor/plf/aic8800/src/driver/usb_host/usbh_conf.c
    vendor/plf/aic8800/src/driver/usb_host/usbh_core.c
    vendor/plf/aic8800/src/driver/usb_host/usbh_ctlreq.c
    vendor/plf/aic8800/src/driver/usb_host/usbh_ioreq.c
    vendor/plf/aic8800/src/driver/usb_host/usbh_msc.c
    vendor/plf/aic8800/src/driver/usb_host/usbh_msc_bot.c
    vendor/plf/aic8800/src/driver/usb_host/usbh_msc_scsi.c
    vendor/plf/aic8800/src/driver/usb_host/usbh_pipes.c
    vendor/plf/aic8800/src/driver/wdt/wdt_api.c

    vendor/wifi/fhost/fhost_config.c
    vendor/wifi/macif/rom_patch.c
)
