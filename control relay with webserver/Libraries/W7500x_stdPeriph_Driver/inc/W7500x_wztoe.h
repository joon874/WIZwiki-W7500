/*
 *********************************************************************
 * @file    : wztoe.h
 * @version : 1.0.1
 * @author  : WIZnet
 * @data    19-May-2015
 * @brief   : WZTOE dirver for W7500
 *********************************************************************
 * @attention
 * @par Revision history
 *    <2015/05/19> V1.0.1 by justinKim
 *      1. getSn_DIPR - IP Address Bug fix
 *      2. getSn_DHAR - SHAR -> DHAR  Bug fix
 *    <2015/05/01> 1st Release
 */
 


#ifndef __WZTOE_H
#define __WZTOE_H
#include "W7500x.h"
#include <stdio.h>
#include <stdint.h>


/* Peripheral base address */
#define W7500x_WZTOE_BASE   (0x46000000)//(W7500x_AHB_BASE + 0x06000000UL)

/* WZTOE register and MEMs memory map */
//-----------------------------------------
// TX and RX Mermory address  
//-----------------------------------------
#define TXMEM_BASE          (W7500x_WZTOE_BASE + 0x00020000)
#define RXMEM_BASE          (W7500x_WZTOE_BASE + 0x00030000)
//-----------------------------------------
// Common Register address
//-----------------------------------------
#define VENDOR_INFO         (W7500x_WZTOE_BASE + 0x00000000) 
#define SYS_BASE            (W7500x_WZTOE_BASE + 0x00002000) 
#define PHY_BASE            (W7500x_WZTOE_BASE + 0x00004000) 
#define NETIPV4_BASE        (W7500x_WZTOE_BASE + 0x00006000) 

#define VERSIONR            (VENDOR_INFO)
#define TIC100US            (SYS_BASE)

#define IR                  (W7500x_WZTOE_BASE + 0x00002100) //Interrupt
#define IMR                 (W7500x_WZTOE_BASE + 0x00002104)
#define __ICR                 (W7500x_WZTOE_BASE + 0x00002108)
#define SIR                 (W7500x_WZTOE_BASE + 0x00002110)
#define SIMR                (W7500x_WZTOE_BASE + 0x00002114)
#define INTLEVEL            (W7500x_WZTOE_BASE + 0x00002200)

#define MR                  (W7500x_WZTOE_BASE + 0x00002300) //Mode Register
#define MR1                 (W7500x_WZTOE_BASE + 0x00002301) //Mode Register

#define PTIMER              (W7500x_WZTOE_BASE + 0x00002400) //PPPoE Timer Register
#define PMAGIC              (W7500x_WZTOE_BASE + 0x00002404) //PPPoE LCP Magic number in PPPoE
#define PHAR                (W7500x_WZTOE_BASE + 0x00002408)
#define PSID                (W7500x_WZTOE_BASE + 0x00002410)
#define PMRU                (W7500x_WZTOE_BASE + 0x00002414)

#define SHAR                (W7500x_WZTOE_BASE + 0x00006000) //Network IPv4
#define GAR                 (W7500x_WZTOE_BASE + 0x00006008)
#define SUBR                (W7500x_WZTOE_BASE + 0x0000600C)
#define SIPR                (W7500x_WZTOE_BASE + 0x00006010)
#define NETCFGLOCK          (W7500x_WZTOE_BASE + 0x00006020) 
#define RTR                 (W7500x_WZTOE_BASE + 0x00006040) //Conf IPvr
#define RCR                 (W7500x_WZTOE_BASE + 0x00006044)
#define UIPR                (W7500x_WZTOE_BASE + 0x00006050) //Port unreachable
#define UPORTR              (W7500x_WZTOE_BASE + 0x00006054) 

//-----------------------------------------
// Socket Register address
//-----------------------------------------
#define Sn_MR(ch)           (W7500x_WZTOE_BASE + (0x00010000 + ((ch)<<18))) 
#define Sn_CR(ch)           (W7500x_WZTOE_BASE + (0x00010010 + ((ch)<<18))) 
#define Sn_ISR(ch)          (W7500x_WZTOE_BASE + (0x00010020 + ((ch)<<18))) 
#define Sn_IMR(ch)          (W7500x_WZTOE_BASE + (0x00010024 + ((ch)<<18))) 
#define Sn_ICR(ch)          (W7500x_WZTOE_BASE + (0x00010028 + ((ch)<<18))) 
#define Sn_SR(ch)           (W7500x_WZTOE_BASE + (0x00010030 + ((ch)<<18))) 

#define Sn_PROTO(ch)        (W7500x_WZTOE_BASE + (0x00010100 + ((ch)<<18))) 
#define Sn_TOS(ch)          (W7500x_WZTOE_BASE + (0x00010104 + ((ch)<<18))) 
#define Sn_TTL(ch)          (W7500x_WZTOE_BASE + (0x00010108 + ((ch)<<18)))
#define Sn_FRG(ch)          (W7500x_WZTOE_BASE + (0x0001010C + ((ch)<<18)))
#define Sn_MSSR(ch)         (W7500x_WZTOE_BASE + (0x00010110 + ((ch)<<18))) 
#define Sn_PORT(ch)         (W7500x_WZTOE_BASE + (0x00010114 + ((ch)<<18))) 
#define Sn_DHAR(ch)         (W7500x_WZTOE_BASE + (0x00010118 + ((ch)<<18))) 
#define Sn_DPORT(ch)        (W7500x_WZTOE_BASE + (0x00010120 + ((ch)<<18))) 
#define Sn_DIPR(ch)         (W7500x_WZTOE_BASE + (0x00010124 + ((ch)<<18)))
#define Sn_DIPR1(ch)         (W7500x_WZTOE_BASE + (0x00010125 + ((ch)<<18)))
#define Sn_DIPR2(ch)         (W7500x_WZTOE_BASE + (0x00010126 + ((ch)<<18)))
#define Sn_DIPR3(ch)         (W7500x_WZTOE_BASE + (0x00010127 + ((ch)<<18)))

#define Sn_KPALVTR(ch)      (W7500x_WZTOE_BASE + (0x00010180 + ((ch)<<18))) 
#define Sn_TXBUF_SIZE(ch)   (W7500x_WZTOE_BASE + (0x00010200 + ((ch)<<18))) 
#define Sn_TX_FSR(ch)       (W7500x_WZTOE_BASE + (0x00010204 + ((ch)<<18))) 
#define Sn_TX_RD(ch)        (W7500x_WZTOE_BASE + (0x00010208 + ((ch)<<18))) 
#define Sn_TX_WR(ch)        (W7500x_WZTOE_BASE + (0x0001020C + ((ch)<<18))) 
#define Sn_RXBUF_SIZE(ch)   (W7500x_WZTOE_BASE + (0x00010220 + ((ch)<<18))) 
#define Sn_RX_RSR(ch)       (W7500x_WZTOE_BASE + (0x00010224 + ((ch)<<18))) 
#define Sn_RX_RD(ch)        (W7500x_WZTOE_BASE + (0x00010228 + ((ch)<<18))) 
#define Sn_RX_WR(ch)        (W7500x_WZTOE_BASE + (0x0001022C + ((ch)<<18))) 
//#define Sn_TSR(ch)        (W7500x_WZTOE_BASE + (0x00010400 + ((ch)<<18))) 
//-----------------------------------------

/* Variable Values */
//-----------------------------------------
// Register Values 
//-----------------------------------------
// MODE register values
#define MR_NOTCPRSTPKT      (0x0200) /**< No Send TCP RESET PACKET */
#define MR_SKIPSRCMAC       (0x0100) /**< SKIP Source MAC Check for test */
#define MR_RST              (0x0080) /**< reset */
#define MR_WOL              (0x0020) /**< Wake on Lan */
#define MR_PB               (0x0010) /**< ping block */
#define MR_PPPOE            (0x0008) /**< enable pppoe */
#define MR_FARP             (0x0002) /**< enbale FORCE ARP */

// IR register values 
#define IR_CONFLICT         (0x80) /**< check ip confict */
#define IR_UNREACH          (0x40) /**< get the destination unreachable message in UDP sending */
#define IR_PPPoE            (0x20) /**< get the PPPoE close message */
#define IR_MP               (0x10) /**< get the magic packet interrupt */
#define IM_IR7              IR_CONFLICT //0x80
#define IM_IR6              IR_UNREACH
#define IM_IR5              IR_PPPoE
#define IM_IR4              IR_MP

// Sn_MR values 
#define Sn_MR_MULTI         (0x80)     /**< support UDP Multicating */
#define Sn_MR_BCASTB        (0x40)     /**< support UDP Broadcasting */
#define Sn_MR_FPSHCLR       (0x40)     /**< IPv4 clear PSH flag in TCP */
#define Sn_MR_ND            (0x20)     /**< No Delayed Ack(TCP) flag */
#define Sn_MR_MC            (0x20)     /**< Multicast IGMP (UDP) flag */
#define Sn_MR_UCASTB        (0x10)     /**< Unicast Block in UDP Multicating*/
#define Sn_MR_PPPOE         (0x05)     /**< PPPoE */
#define Sn_MR_MACRAW        (0x04)     /**< MAC LAYER RAW SOCK */
#define Sn_MR_IPRAW         (0x03)     /**< IP LAYER RAW SOCK */
#define Sn_MR_UDP           (0x02)     /**< UDP */
#define Sn_MR_TCP           (0x01)     /**< TCP */
#define Sn_MR_CLOSE         (0x00)     /**< unused socket */

// Sn_MR values in MACRAW MODE 
#define Sn_MR_MFEN          (Sn_MR_MULTI)     /**< support MAC filter enable */
#define Sn_MR_MMB           (Sn_MR_ND)     /**< IPv4 Multicasting Block */
#define Sn_MR_MIP6B         (Sn_MR_UCASTB)     /**< IPv6 packet Block */

/**
 * @brief For Berkeley Socket API
 */
#define SOCK_STREAM         Sn_MR_TCP
#define SOCK_DGRAM          Sn_MR_UDP


// Sn_CR values 
#define Sn_CR_OPEN          (0x01)     /**< initialize or open socket */
#define Sn_CR_LISTEN        (0x02)     /**< wait connection request in tcp mode(Server mode) */
#define Sn_CR_CONNECT       (0x04)     /**< send connection request in tcp mode(Client mode) */
#define Sn_CR_DISCON        (0x08)     /**< send closing reqeuset in tcp mode */
#define Sn_CR_CLOSE         (0x10)     /**< close socket */
#define Sn_CR_SEND          (0x20)     /**< update txbuf pointer, send data */
#define Sn_CR_SEND_MAC      (0x21)     /**< send data with MAC address, so without ARP process */
#define Sn_CR_SEND_KEEP     (0x22)     /**<  send keep alive message */
#define Sn_CR_RECV          (0x40)     /**< update rxbuf pointer, recv data */
#ifdef __DEF_IINCHIP_PPP__
#define Sn_CR_PCON          (0x23)      
#define Sn_CR_PDISCON       (0x24)      
#define Sn_CR_PCR           (0x25)      
#define Sn_CR_PCN           (0x26)     
#define Sn_CR_PCJ           (0x27)     
#endif


// Sn_IR values 
#define Sn_IR_SENDOK        (0x10)     /**< complete sending */
#define Sn_IR_TIMEOUT       (0x08)     /**< assert timeout */
#define Sn_IR_RECV          (0x04)     /**< receiving data */
#define Sn_IR_DISCON        (0x02)     /**< closed socket */
#define Sn_IR_CON           (0x01)     /**< established connection */
#ifdef __DEF_IINCHIP_PPP__
#define Sn_IR_PNEXT         (0x20)     
#define Sn_IR_PFAIL         (0x40)     
#define Sn_IR_PRECV         (0x80)     
#endif

// Sn_SR values 
#define SOCK_CLOSED         (0x00)     /**< closed */
#define SOCK_INIT           (0x13)     /**< init state */
#define SOCK_LISTEN         (0x14)     /**< listen state */
#define SOCK_SYNSENT        (0x15)     /**< connection state */
#define SOCK_SYNRECV        (0x16)     /**< connection state */
#define SOCK_ESTABLISHED    (0x17)     /**< success to connect */
#define SOCK_FIN_WAIT       (0x18)     /**< closing state */
#define SOCK_CLOSING        (0x1A)     /**< closing state */
#define SOCK_TIME_WAIT      (0x1B)     /**< closing state */
#define SOCK_CLOSE_WAIT     (0x1C)     /**< closing state */
#define SOCK_LAST_ACK       (0x1D)     /**< closing state */
#define SOCK_UDP            (0x22)     /**< udp socket */
#define SOCK_IPRAW          (0x32)     /**< ip raw mode socket */
#define SOCK_MACRAW         (0x42)     /**< mac raw mode socket */
#define SOCK_PPPOE          (0x5F)     /**< pppoe socket */

// IP PROTOCOL 
#define IPPROTO_IP          (0  )      /**< Dummy for IP */
#define IPPROTO_ICMP        (1  )      /**< Control message protocol */
#define IPPROTO_IGMP        (2  )      /**< Internet group management protocol */
#define IPPROTO_GGP         (3  )      /**< Gateway^2 (deprecated) */
#define IPPROTO_TCP         (6  )      /**< TCP */
#define IPPROTO_PUP         (12 )      /**< PUP */
#define IPPROTO_UDP         (17 )      /**< UDP */
#define IPPROTO_IDP         (22 )      /**< XNS idp */
#define IPPROTO_ND          (77 )      /**< UNOFFICIAL net disk protocol */
#define IPPROTO_RAW         (255)      /**< Raw IP packet */
/**
 * @brief Enter a critical section
 * @brief Exit a critical section
 */
#define WIZCHIP_CRITICAL_ENTER()     //WIZCHIP.CRIS._enter()
#define WIZCHIP_CRITICAL_EXIT()     //WIZCHIP.CRIS._exit()
////////////////////////
// Basic I/O Function //
////////////////////////
uint8_t WIZCHIP_READ(uint32_t Addr);
void WIZCHIP_WRITE(uint32_t Addr, uint8_t Data);
void WIZCHIP_READ_BUF (uint32_t BaseAddr, uint32_t ptr, uint8_t* pBuf, uint16_t len);
void WIZCHIP_WRITE_BUF(uint32_t BaseAddr, uint32_t ptr, uint8_t* pBuf, uint16_t len);
//-----------------------------------------
// wztoe utils 
//-----------------------------------------
//#define htole32(x) \
//	(((((uint32_t)x) & 0xff000000) >> 24) | \
//	 ((((uint32_t)x) & 0x00ff0000) >> 8) | \
//	 ((((uint32_t)x) & 0x0000ff00) << 8) | \
//	 ((((uint32_t)x) & 0x000000ff) << 24))
//
//#define htole16(x) \
//	(((((uint16_t)x) & 0xff00) >> 8) | \
//	 ((((uint16_t)x) & 0x00ff) << 8)) 
/////////////////////////////////
// Common Register I/O function //
/////////////////////////////////
/**
 * @ingroup Version_register_access_function
 * @brief Get Version Register
 * @return uint8_t. The value of Version register.
 * @sa setVERSIONR()
 */
#define getVERSIONR() \
    WIZCHIP_READ(VERSIONR)

/**
 * @ingroup Common_register_access_function
 * @brief Get 100US Register
 * @return uint8_t. The value of 100US register.
 * @sa set100US()
 */
#define getTIC100US() ((uint16_t)(*(volatile uint32_t *)(TIC100US)))

/**
 * @ingroup Common_register_access_function
 * @brief Set 100US Register
 * @param (uint8_t)tic The value to be set.
 * @sa get100US()
 */
#define setTIC100US(tic)  (*(volatile uint32_t *)(TIC100US) = tic)


/**
 * @ingroup Common_register_access_function
 * @brief Set @ref IR register
 * @param (uint8_t)ir Value to set @ref IR register.
 * @sa getIR()
 */
//#define setIR(ir) \
//		WIZCHIP_WRITE(IR, (ir & 0xF0))

/**
 * @ingroup Common_register_access_function
 * @brief Get @ref IR register
 * @return uint8_t. Value of @ref IR register.
 * @sa setIR()
 */
#define getIR() \
    WIZCHIP_READ(IR)
/**
 * @ingroup Common_register_access_function
 * @brief Set @ref IMR register
 * @param (uint8_t)imr Value to set @ref IMR register.
 * @sa getIMR()
 */
#define setIMR(imr) \
    WIZCHIP_WRITE(IMR, (imr&0xF0))

/**
 * @ingroup Common_register_access_function
 * @brief Get @ref IMR register
 * @return uint8_t. Value of @ref IMR register.
 * @sa setIMR()
 */
#define getIMR() \
    WIZCHIP_READ(IMR)


/**
 * @ingroup Common_register_access_function
 * @brief Set @ref ICR register
 * @param (uint8_t)icr Value to set @ref ICR register.
 * @sa getICR()
 */
#define setICR(icr) \
    WIZCHIP_WRITE(__ICR, icr&0xF0)

#define setIR(ir) \
    setICR(ir)
/**
 * @ingroup Common_register_access_function
 * @brief Get @ref ICR register
 * @return uint8_t. Value of @ref ICR register.
 * @sa setICR()
 */
//#define getICR() \
//		WIZCHIP_READ(ICR)

/**
 * @ingroup Common_register_access_function
 * @brief Set @ref SIR register
 * @param (uint8_t)sir Value to set @ref SIR register.
 * @sa getSIR()
 */
#define setSIR(sir) \
    WIZCHIP_WRITE(SIR, sir)

/**
 * @ingroup Common_register_access_function
 * @brief Get @ref SIR register
 * @return uint8_t. Value of @ref SIR register.
 * @sa setSIR()
 */
#define getSIR() \
    WIZCHIP_READ(SIR)
/**
 * @ingroup Common_register_access_function
 * @brief Set @ref SIMR register
 * @param (uint8_t)simr Value to set @ref SIMR register.
 * @sa getSIMR()
 */
#define setSIMR(simr) \
    WIZCHIP_WRITE(SIMR, simr)

/**
 * @ingroup Common_register_access_function
 * @brief Get @ref SIMR register
 * @return uint8_t. Value of @ref SIMR register.
 * @sa setSIMR()
 */
#define getSIMR() \
    WIZCHIP_READ(SIMR)

/**
 * @ingroup Common_register_access_function
 * @brief Set INTLEVEL register
 * @param (uint16_t)intlevel Value to set @ref INTLEVEL register.
 * @sa getINTLEVEL()
 */
#define setINTLEVEL(intlevel) (*(volatile uint32_t *)(INTLEVEL) = intlevel)

/**
 * @ingroup Common_register_access_function
 * @brief Get INTLEVEL register
 * @return uint16_t. Value of @ref INTLEVEL register.
 * @sa setINTLEVEL()
 */
#define getINTLEVEL() ((uint16_t)(*(volatile uint32_t *)(INTLEVEL)))


/**
 * @ingroup Common_register_access_function
 * @brief Get Mode Register
 * @return uint8_t. The value of Mode register.
 * @sa setMR()
 */
#define getMR() \
    WIZCHIP_READ(MR)

/**
 * @ingroup Common_register_access_function
 * @brief Set Mode Register
 * @param (uint8_t)mr The value to be set.
 * @sa getMR()
 */
#define setMR(mr) \
    WIZCHIP_WRITE(MR,mr)

/**
 * @ingroup Common_register_access_function
 * @brief Get Mode Register
 * @return uint8_t. The value of Mode register.
 * @sa setMR()
 */
#define getMR1() \
    WIZCHIP_READ(MR1)

/**
 * @ingroup Common_register_access_function
 * @brief Set Mode Register
 * @param (uint8_t)mr The value to be set.
 * @sa getMR()
 */
#define setMR1(mr) \
    WIZCHIP_WRITE(MR,mr&0x2)
/**
 * @ingroup Common_register_access_function
 * @brief Get Mode Register
 * @return uint8_t. The value of Mode register.
 * @sa setMR()
 */
#define getMR1() \
    WIZCHIP_READ(MR1)

/**
 * @ingroup Common_register_access_function
 * @brief Set @ref PTIMER register
 * @param (uint8_t)ptimer Value to set @ref PTIMER register.
 * @sa getPTIMER()
 */
#define setPTIMER(ptimer) \
    WIZCHIP_WRITE(PTIMER, ptimer)

/**
 * @ingroup Common_register_access_function
 * @brief Get @ref PTIMER register
 * @return uint8_t. Value of @ref PTIMER register.
 * @sa setPTIMER()
 */
#define getPTIMER() \
    WIZCHIP_READ(PTIMER)

/**
 * @ingroup Common_register_access_function
 * @brief Set @ref PMAGIC register
 * @param (uint8_t)pmagic Value to set @ref PMAGIC register.
 * @sa getPMAGIC()
 */
#define setPMAGIC(pmagic) \
    WIZCHIP_WRITE(PMAGIC, pmagic)

/**
 * @ingroup Common_register_access_function
 * @brief Get @ref PMAGIC register
 * @return uint8_t. Value of @ref PMAGIC register.
 * @sa setPMAGIC()
 */
#define getPMAGIC() \
    WIZCHIP_READ(PMAGIC)

/**
 * @ingroup Common_register_access_function
 * @brief Set PHAR address
 * @param (uint8_t*)phar Pointer variable to set PPP destination MAC register address. It should be allocated 6 bytes.
 * @sa getPHAR()
 */
#define setPHAR(phar) \
    WIZCHIP_WRITE(PHAR+3, phar[0]); \
WIZCHIP_WRITE(PHAR+2, phar[1]); \
WIZCHIP_WRITE(PHAR+1, phar[2]); \
WIZCHIP_WRITE(PHAR+0, phar[3]); \
WIZCHIP_WRITE(PHAR+7, phar[4]); \
WIZCHIP_WRITE(PHAR+6, phar[5]); 

/**
 * @ingroup Common_register_access_function
 * @brief Get local IP address
 * @param (uint8_t*)phar Pointer variable to PPP destination MAC register address. It should be allocated 6 bytes.
 * @sa setPHAR()
 */
#define getPHAR(phar) \
    phar[0] = WIZCHIP_READ(PHAR+3); \
phar[1] = WIZCHIP_READ(PHAR+2); \
phar[2] = WIZCHIP_READ(PHAR+1); \
phar[3] = WIZCHIP_READ(PHAR+0); \
phar[4] = WIZCHIP_READ(PHAR+7); \
phar[5] = WIZCHIP_READ(PHAR+6); 

/**
 * @ingroup Common_register_access_function
 * @brief Set @ref PSID register
 * @param (uint16_t)psid Value to set @ref PSID register.
 * @sa getPSID()
 */
#define setPSID(psid) \
    WIZCHIP_WRITE(PSID, psid)

/**
 * @ingroup Common_register_access_function
 * @brief Get @ref PSID register
 * @return uint16_t. Value of @ref PSID register.
 * @sa setPSID()
 */
//uint16_t getPSID(void);
#define getPSID() \
    WIZCHIP_READ(PSID)

/**
 * @ingroup Common_register_access_function
 * @brief Set @ref PMRU register
 * @param (uint16_t)pmru Value to set @ref PMRU register.
 * @sa getPMRU()
 */
#define setPMRU(pmru) \
    WIZCHIP_WRITE(PMRU, pmru)

/**
 * @ingroup Common_register_access_function
 * @brief Get @ref PMRU register
 * @return uint16_t. Value of @ref PMRU register.
 * @sa setPMRU()
 */
#define getPMRU() \
    WIZCHIP_READ(PMRU)

/**
 * @ingroup Common_register_access_function
 * @brief Set local MAC address
 * @param (uint8_t*)shar Pointer variable to set local MAC address. It should be allocated 6 bytes.
 * @sa getSHAR()
 */
#define setSHAR(shar) \
    WIZCHIP_WRITE(SHAR+3, shar[0]); \
WIZCHIP_WRITE(SHAR+2, shar[1]); \
WIZCHIP_WRITE(SHAR+1, shar[2]); \
WIZCHIP_WRITE(SHAR+0, shar[3]); \
WIZCHIP_WRITE(SHAR+7, shar[4]); \
WIZCHIP_WRITE(SHAR+6, shar[5]); 

/**
 * @ingroup Common_register_access_function
 * @brief Get local MAC address
 * @param (uint8_t*)shar Pointer variable to get local MAC address. It should be allocated 6 bytes.
 * @sa setSHAR()
 */
#define getSHAR(shar) \
    shar[0] = WIZCHIP_READ(SHAR+3); \
shar[1] = WIZCHIP_READ(SHAR+2); \
shar[2] = WIZCHIP_READ(SHAR+1); \
shar[3] = WIZCHIP_READ(SHAR+0); \
shar[4] = WIZCHIP_READ(SHAR+7); \
shar[5] = WIZCHIP_READ(SHAR+6); 

/**
 * @ingroup Common_register_access_function
 * @brief Set gateway IP address
 * @param (uint8_t*)gar Pointer variable to set gateway IP address. It should be allocated 4 bytes.
 * @sa getGAR()
 */
//#define setGAR(gar) (*(volatile uint32_t *)(GAR) = htole32(*(volatile uint32_t *)(gar)))
#define setGAR(gar) \
    WIZCHIP_WRITE((GAR+3), gar[0]); \
WIZCHIP_WRITE((GAR+2), gar[1]); \
WIZCHIP_WRITE((GAR+1), gar[2]); \
WIZCHIP_WRITE((GAR  ), gar[3]); 


/**
 * @ingroup Common_register_access_function
 * @brief Get gateway IP address
 * @param (uint8_t*)gar Pointer variable to get gateway IP address. It should be allocated 4 bytes.
 * @sa setGAR()
 */
//#define getGAR(gar) (*(volatile uint32_t *)(gar) = htole32(*(volatile uint32_t *)(GAR)))
#define getGAR(gar) \
    gar[0] = WIZCHIP_READ((GAR+3)); \
gar[1] = WIZCHIP_READ((GAR+2)); \
gar[2] = WIZCHIP_READ((GAR+1)); \
gar[3] = WIZCHIP_READ((GAR+0));

/**
 * @ingroup Common_register_access_function
 * @brief Set subnet mask address
 * @param (uint8_t*)subr Pointer variable to set subnet mask address. It should be allocated 4 bytes.
 * @sa getSUBR()
 */
//#define setSUBR(subr) (*(volatile uint32_t *)(SUBR) = htole32(*(volatile uint32_t *)(subr)))
#define setSUBR(subr) \
    WIZCHIP_WRITE((SUBR+3), subr[0]); \
WIZCHIP_WRITE((SUBR+2), subr[1]); \
WIZCHIP_WRITE((SUBR+1), subr[2]); \
WIZCHIP_WRITE((SUBR  ), subr[3]); 



/**
 * @ingroup Common_register_access_function
 * @brief Get subnet mask address
 * @param (uint8_t*)subr Pointer variable to get subnet mask address. It should be allocated 4 bytes.
 * @sa setSUBR()
 */
//#define getSUBR(subr) (*(volatile uint32_t *)(subr) = htole32(*(volatile uint32_t *)(SUBR)))
#define getSUBR(subr) \
    subr[0] = WIZCHIP_READ((SUBR+3)); \
subr[1] = WIZCHIP_READ((SUBR+2)); \
subr[2] = WIZCHIP_READ((SUBR+1)); \
subr[3] = WIZCHIP_READ((SUBR+0));

/**
 * @ingroup Common_register_access_function
 * @brief Set local IP address
 * @param (uint8_t*)sipr Pointer variable to set local IP address. It should be allocated 4 bytes.
 * @sa getSIPR()
 */
//#define setSIPR(sipr) (*(volatile uint32_t *)(SIPR) = htole32(*(volatile uint32_t *)(sipr)))
#define setSIPR(sipr) \
    WIZCHIP_WRITE((SIPR+3), sipr[0]); \
WIZCHIP_WRITE((SIPR+2), sipr[1]); \
WIZCHIP_WRITE((SIPR+1), sipr[2]); \
WIZCHIP_WRITE((SIPR  ), sipr[3]); 

/**
 * @ingroup Common_register_access_function
 * @brief Get local IP address
 * @param (uint8_t*)sipr Pointer variable to get local IP address. It should be allocated 4 bytes.
 * @sa setSIPR()
 */
//#define getSIPR(sipr) (*(volatile uint32_t *)(sipr) = htole32(*(volatile uint32_t *)(SIPR)))
#define getSIPR(sipr) \
    sipr[0] = WIZCHIP_READ((SIPR+3)); \
sipr[1] = WIZCHIP_READ((SIPR+2)); \
sipr[2] = WIZCHIP_READ((SIPR+1)); \
sipr[3] = WIZCHIP_READ((SIPR+0));

/**
 * @ingroup Common_register_access_function
 * @brief lock NETCFGLOCK 
 * @sa lockNETCFGLOCK()
 */
#define lockNETCFGLOCK() (*(volatile uint32_t *)(NETCFGLOCK) = 0x00)

/**
 * @ingroup Common_register_access_function
 * @brief unlock NETCFGLOCK
 * @sa unlockNETCFGLOCK()
 */
#define unlockNETCFGLOCK32() (*(volatile uint32_t *)(NETCFGLOCK) = 0x1ACCE55)

/**
 * @ingroup Common_register_access_function
 * @brief Set @ref RTR register
 * @param (uint16_t)rtr Value to set @ref RTR register.
 * @sa setRTR()
 */
#define setRTR(rtr) (*(volatile uint32_t *)(RTR) = rtr)

/**
 * @ingroup Common_register_access_function
 * @brief Get @ref RTR register
 * @return uint16_t. Value of @ref RTR register.
 * @sa getRTR()
 */
#define getRTR() ((uint16_t)(*(volatile uint32_t *)(RTR)))

/**
 * @ingroup Common_register_access_function
 * @brief Set @ref RCR register
 * @param (uint8_t)rcr Value to set @ref RCR register.
 * @sa getRCR()
 */
#define setRCR(rcr) \
    WIZCHIP_WRITE(RCR, rcr)

/**
 * @ingroup Common_register_access_function
 * @brief Get @ref RCR register
 * @return uint8_t. Value of @ref RCR register.
 * @sa setRCR()
 */
#define getRCR() \
    WIZCHIP_READ(RCR)

/**
 * @ingroup Common_register_access_function
 * @brief Get unreachable IP address
 * @param (uint8_t*)uipr Pointer variable to get unreachable IP address. It should be allocated 4 bytes.
 */
//#define getUIPR(uipr) (*(volatile uint32_t *)(uipr) = htole32(*(volatile uint32_t *)(UIPR)))
#define getUIPR(uipr) \
    uipr[0] = WICHIP_READ((UIPR+3)); \
uipr[1] = WIZCHIP_READ((UIPR+2)); \
uipr[2] = WIZCHIP_READ((UIPR+1)); \
uipr[3] = WIZCHIP_READ((UIPR));

/**
 * @ingroup Common_register_access_function
 * @brief Get @ref UPORTR register
 * @return uint16_t. Value of @ref UPORTR register.
 */
#define getUPORTR()  ((uint16_t)((volatile uint32_t *)(UPORTR)))
/////////////////////////////////////

///////////////////////////////////
// Socket N register I/O function //
///////////////////////////////////
/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_MR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint8_t)mr Value to set @ref Sn_MR
 * @sa getSn_MR()
 */
#define setSn_MR(sn, mr) \
    WIZCHIP_WRITE(Sn_MR(sn),mr)

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_MR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint8_t. Value of @ref Sn_MR.
 * @sa setSn_MR()
 */
#define getSn_MR(sn) \
    WIZCHIP_READ(Sn_MR(sn))

/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_CR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint8_t)cr Value to set @ref Sn_CR
 * @sa getSn_CR()
 */
#define setSn_CR(sn, cr) \
    WIZCHIP_WRITE(Sn_CR(sn), cr)

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_CR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint8_t. Value of @ref Sn_CR.
 * @sa setSn_CR()
 */
#define getSn_CR(sn) \
    WIZCHIP_READ(Sn_CR(sn))

/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_IR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint8_t)ir Value to set @ref Sn_IR
 * @sa getSn_IR()
 */
//#define setSn_IR(sn, ir) \
//		WIZCHIP_WRITE(Sn_IR(sn), (ir & 0x1F))

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_IR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint8_t. Value of @ref Sn_IR.
 * @sa setSn_IR()
 */
#define getSn_IR(sn) \
    (WIZCHIP_READ(Sn_ISR(sn)) & 0x1F)

/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_IMR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint8_t)imr Value to set @ref Sn_IMR
 * @sa getSn_IMR()
 */
#define setSn_IMR(sn, imr) \
    WIZCHIP_WRITE(Sn_IMR(sn), (imr & 0x1F))

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_IMR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint8_t. Value of @ref Sn_IMR.
 * @sa setSn_IMR()
 */
#define getSn_IMR(sn) \
    (WIZCHIP_READ(Sn_IMR(sn)) & 0x1F)
/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_ICR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint8_t)icr Value to set @ref Sn_ICR
 * @sa getSn_ICR()
 */
#define setSn_ICR(sn, icr) \
    WIZCHIP_WRITE(Sn_ICR(sn), (icr & 0x1F))

#define setSn_IR(sn, icr) \
    setSn_ICR(sn, icr)

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_ICR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint8_t. Value of @ref Sn_ICR.
 * @sa setSn_ICR()
 */
#define getSn_ICR(sn) \
    (WIZCHIP_READ(Sn_ICR(sn)) & 0x1F)

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_SR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint8_t. Value of @ref Sn_SR.
 */
#define getSn_SR(sn) \
    WIZCHIP_READ(Sn_SR(sn))

/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_PROTO register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint8_t)tos Value to set @ref Sn_PROTO
 * @sa getSn_PROTO()
 */
#define setSn_PROTO(sn, proto) \
    WIZCHIP_WRITE(Sn_PROTO(sn), proto)

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_PROTO register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint8_t. Value of Sn_PROTO.
 * @sa setSn_PROTO()
 */
#define getSn_PROTO(sn) \
    WIZCHIP_READ(Sn_PROTO(sn))

/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_TOS register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint8_t)tos Value to set @ref Sn_TOS
 * @sa getSn_TOS()
 */
#define setSn_TOS(sn, tos) \
    WIZCHIP_WRITE(Sn_TOS(sn), tos)

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_TOS register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint8_t. Value of Sn_TOS.
 * @sa setSn_TOS()
 */
#define getSn_TOS(sn) \
    WIZCHIP_READ(Sn_TOS(sn))

/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_TTL register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint8_t)ttl Value to set @ref Sn_TTL
 * @sa getSn_TTL()
 */
#define setSn_TTL(sn, ttl) \
    WIZCHIP_WRITE(Sn_TTL(sn), ttl)

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_TTL register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint8_t. Value of @ref Sn_TTL.
 * @sa setSn_TTL()
 */
#define getSn_TTL(sn) \
    WIZCHIP_READ(Sn_TTL(sn))

/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_FRAG register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint16_t)frag Value to set @ref Sn_FRAG
 * @sa getSn_FRAD()
 */
#define setSn_FRAG(sn, frag) (*(volatile uint32_t *)(Sn_FRAG(sn)) = frag)

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_FRAG register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint16_t. Value of @ref Sn_FRAG.
 * @sa setSn_FRAG()
 */
#define getSn_FRAG(sn) ((uint16_t)(*(volatile uint32_t *)(Sn_FRAG(sn))))

/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_MSSR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint16_t)mss Value to set @ref Sn_MSSR
 * @sa setSn_MSSR()
 */
#define setSn_MSSR(sn, mss) (*(volatile uint32_t *)(Sn_MSSR(sn)) = mss)

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_MSSR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint16_t. Value of @ref Sn_MSSR.
 * @sa setSn_MSSR()
 */
#define getSn_MSSR(sn) ((uint16_t)(*(volatile uint32_t *)(Sn_MSSR(sn))))

/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_PORT register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint16_t)port Value to set @ref Sn_PORT.
 * @sa getSn_PORT()
 */
#define setSn_PORT(sn, port) (*(volatile uint32_t *)(Sn_PORT(sn)) = port)

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_PORT register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint16_t. Value of @ref Sn_PORT.
 * @sa setSn_PORT()
 */
#define getSn_PORT(sn) ((uint16_t)(*(volatile uint32_t *)(Sn_PORT(sn))))

/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_DHAR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint8_t*)dhar Pointer variable to set socket n destination hardware address. It should be allocated 6 bytes.
 * @sa getSn_DHAR()
 */
#define setSn_DHAR(sn, dhar) \
    WIZCHIP_WRITE((Sn_DHAR(sn)+3), dhar[0]); \
    WIZCHIP_WRITE((Sn_DHAR(sn)+2), dhar[1]); \
    WIZCHIP_WRITE((Sn_DHAR(sn)+1), dhar[2]); \
    WIZCHIP_WRITE((Sn_DHAR(sn)+0), dhar[3]); \
    WIZCHIP_WRITE((Sn_DHAR(sn)+7), dhar[4]); \
    WIZCHIP_WRITE((Sn_DHAR(sn)+6), dhar[5]); 

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_MR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint8_t*)dhar Pointer variable to get socket n destination hardware address. It should be allocated 6 bytes.
 * @sa setSn_DHAR()
 */
 //15.05.19 by justinKim
#define getSn_DHAR(sn, dhar) \
    dhar[0] = WIZCHIP_READ((Sn_DHAR(sn)+3)); \
    dhar[1] = WIZCHIP_READ((Sn_DHAR(sn)+2)); \
    dhar[2] = WIZCHIP_READ((Sn_DHAR(sn)+1)); \
    dhar[3] = WIZCHIP_READ((Sn_DHAR(sn)+0)); \
    dhar[4] = WIZCHIP_READ((Sn_DHAR(sn)+7)); \
    dhar[5] = WIZCHIP_READ((Sn_DHAR(sn)+6)); 

/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_DPORT register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint16_t)dport Value to set @ref Sn_DPORT
 * @sa getSn_DPORT()
 */
#define setSn_DPORT(sn, dport) (*(volatile uint32_t *)(Sn_DPORT(sn)) = dport)

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_DPORT register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint16_t. Value of @ref Sn_DPORT.
 * @sa setSn_DPORT()
 */
#define getSn_DPORT(sn) ((uint16_t)(*(volatile uint32_t *)(Sn_DPORT(sn))))

/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_DIPR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint8_t*)dipr Pointer variable to set socket n destination IP address. It should be allocated 4 bytes.
 * @sa getSn_DIPR()
 */
//15.05.19 by justinKim
#define setSn_DIPR(sn, dipr) { \
    WIZCHIP_WRITE((Sn_DIPR3(sn)), dipr[0]); \
    WIZCHIP_WRITE((Sn_DIPR2(sn)), dipr[1]); \
    WIZCHIP_WRITE((Sn_DIPR1(sn)), dipr[2]); \
    WIZCHIP_WRITE((Sn_DIPR(sn)),   dipr[3]); \
}
//#define setSn_DIPR(sn, dipr) \

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_DIPR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint8_t*)dipr Pointer variable to get socket n destination IP address. It should be allocated 4 bytes.
 * @sa SetSn_DIPR()
 */
//#define getSn_DIPR(sn, dipr) (*(volatile uint32_t *)(dipr) = htole32(*(volatile uint32_t *)(Sn_DIPR(sn))))
//15.05.19 by justinKim
#define getSn_DIPR(sn, dipr) \
    (dipr)[0] = WIZCHIP_READ(Sn_DIPR3(sn)); \
    (dipr)[1] = WIZCHIP_READ(Sn_DIPR2(sn)); \
    (dipr)[2] = WIZCHIP_READ(Sn_DIPR1(sn)); \
    (dipr)[3] = WIZCHIP_READ(Sn_DIPR(sn)); 

/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_KPALVTR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint8_t)kpalvt Value to set @ref Sn_KPALVTR
 * @sa getSn_KPALVTR()
 */
#define setSn_KPALVTR(sn, kpalvt) \
    WIZCHIP_WRITE(Sn_KPALVTR(sn), kpalvt)

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_KPALVTR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint8_t. Value of @ref Sn_KPALVTR.
 * @sa setSn_KPALVTR()
 */
#define getSn_KPALVTR(sn) \
    WIZCHIP_READ(Sn_KPALVTR(sn))

/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_TXBUF_SIZE register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint8_t)txbufsize Value to set @ref Sn_TXBUF_SIZE
 * @sa getSn_TXBUF_SIZE()
 */
#define setSn_TXBUF_SIZE(sn, txbufsize) \
    WIZCHIP_WRITE(Sn_TXBUF_SIZE(sn), txbufsize)

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_TXBUF_SIZE register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint8_t. Value of @ref Sn_TXBUF_SIZE.
 * @sa setSn_TXBUF_SIZE()
 */
#define getSn_TXBUF_SIZE(sn) \
    WIZCHIP_READ(Sn_TXBUF_SIZE(sn))

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_TX_FSR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint16_t. Value of @ref Sn_TX_FSR.
 */
#define getSn_TX_FSR(sn) ((uint16_t)(*(volatile uint32_t *)(Sn_TX_FSR(sn))))

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_TX_RD register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint16_t. Value of @ref Sn_TX_RD.
 */
#define getSn_TX_RD(sn) ((uint16_t)(*(volatile uint32_t *)(Sn_TX_RD(sn))))

/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_TX_WR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint16_t)txwr Value to set @ref Sn_TX_WR
 * @sa GetSn_TX_WR()
 */
#define setSn_TX_WR(sn, txwr) (*(volatile uint32_t *)(Sn_TX_WR(sn)) = txwr)

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_TX_WR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint16_t. Value of @ref Sn_TX_WR.
 * @sa setSn_TX_WR()
 */
#define getSn_TX_WR(sn) ((uint16_t)(*(volatile uint32_t *)(Sn_TX_WR(sn))))

/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_RXBUF_SIZE register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint8_t)rxbufsize Value to set @ref Sn_RXBUF_SIZE
 * @sa getSn_RXBUF_SIZE()
 */
#define setSn_RXBUF_SIZE(sn, rxbufsize) \
    WIZCHIP_WRITE(Sn_RXBUF_SIZE(sn),rxbufsize)

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_RXBUF_SIZE register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint8_t. Value of @ref Sn_RXBUF_SIZE.
 * @sa setSn_RXBUF_SIZE()
 */
#define getSn_RXBUF_SIZE(sn) \
    WIZCHIP_READ(Sn_RXBUF_SIZE(sn))

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_RX_RSR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint16_t. Value of @ref Sn_RX_RSR.
 */
#define getSn_RX_RSR(sn) ((uint16_t)(*(volatile uint32_t *)(Sn_RX_RSR(sn))))

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_RX_RD register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @regurn uint16_t. Value of @ref Sn_RX_RD.
 * @sa setSn_RX_RD()
 */
#define setSn_RX_RD(sn, rxrd) (*(volatile uint32_t *)(Sn_RX_RD(sn)) = rxrd)

/**
 * @ingroup Socket_register_access_function
 * @brief Set @ref Sn_RX_RD register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param (uint16_t)rxrd Value to set @ref Sn_RX_RD
 * @sa getSn_RX_RD()
 */
#define getSn_RX_RD(sn)  ((uint16_t)(*(volatile uint32_t *)(Sn_RX_RD(sn))))

/**
 * @ingroup Socket_register_access_function
 * @brief Get @ref Sn_RX_WR register
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint16_t. Value of @ref Sn_RX_WR.
 */
#define getSn_RX_WR(sn) ((uint16_t)(*(volatile uint32_t *)(Sn_RX_WR(sn))))

//////////////////////////////////////

/////////////////////////////////////
// Sn_TXBUF & Sn_RXBUF IO function //
/////////////////////////////////////
/**  
 * @brief Gets the max buffer size of socket sn passed as parameter.
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint16_t. Value of Socket n RX max buffer size.
 */
#define getSn_RxMAX(sn) \
    (getSn_RXBUF_SIZE(sn) << 10)

/**  
 * @brief Gets the max buffer size of socket sn passed as parameters.
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @return uint16_t. Value of Socket n TX max buffer size.
 */
//uint16_t getSn_TxMAX(uint8_t sn);
#define getSn_TxMAX(sn) \
    (getSn_TXBUF_SIZE(sn) << 10)

/**
 * @ingroup Basic_IO_function
 * @brief It copies data to internal TX memory
 *
 * @details This function reads the Tx write pointer register and after that,
 * it copies the <i>wizdata(pointer buffer)</i> of the length of <i>len(variable)</i> bytes to internal TX memory
 * and updates the Tx write pointer register.
 * This function is being called by send() and sendto() function also.
 *
 * @note User should read upper byte first and lower byte later to get proper value.
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param wizdata Pointer buffer to write data
 * @param len Data length
 * @sa wiz_recv_data()
 */
void wiz_send_data(uint8_t sn, uint8_t *wizdata, uint16_t len);

/**
 * @ingroup Basic_IO_function
 * @brief It copies data to your buffer from internal RX memory
 *
 * @details This function read the Rx read pointer register and after that,
 * it copies the received data from internal RX memory
 * to <i>wizdata(pointer variable)</i> of the length of <i>len(variable)</i> bytes.
 * This function is being called by recv() also.
 *
 * @note User should read upper byte first and lower byte later to get proper value.
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param wizdata Pointer buffer to read data
 * @param len Data length
 * @sa wiz_send_data()
 */
void wiz_recv_data(uint8_t sn, uint8_t *wizdata, uint16_t len);

/**
 * @ingroup Basic_IO_function
 * @brief It discard the received data in RX memory.
 * @details It discards the data of the length of <i>len(variable)</i> bytes in internal RX memory.
 * @param (uint8_t)sn Socket number. It should be <b>0 ~ 7</b>.
 * @param len Data length
 */
void wiz_recv_ignore(uint8_t sn, uint16_t len);

#endif

