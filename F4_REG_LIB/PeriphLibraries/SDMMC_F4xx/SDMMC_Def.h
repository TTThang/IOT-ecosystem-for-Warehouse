/*
 * SDMMC_Def.h
 *
 *  Created on: Dec 12, 2022
 *      Author: anh
 */

#ifndef SDMMC_DEF_H_
#define SDMMC_DEF_H_

#include "PERIPH_USED.h"
#ifdef ENABLE_SDMMC

#include "stm32f4xx.h"

#define SDMMC_ERROR_NONE                                0x00000000U    /*!< No error                                                      */
#define SDMMC_ERROR_CMD_CRC_FAIL                        0x00000001U    /*!< Command response received (but CRC check failed)              */
#define SDMMC_ERROR_DATA_CRC_FAIL                       0x00000002U    /*!< Data block sent/received (CRC check failed)                   */
#define SDMMC_ERROR_CMD_RSP_TIMEOUT                     0x00000004U    /*!< Command response timeout                                      */
#define SDMMC_ERROR_DATA_TIMEOUT                        0x00000008U    /*!< Data timeout                                                  */
#define SDMMC_ERROR_TX_UNDERRUN                         0x00000010U    /*!< Transmit FIFO underrun                                        */
#define SDMMC_ERROR_RX_OVERRUN                          0x00000020U    /*!< Receive FIFO overrun                                          */
#define SDMMC_ERROR_ADDR_MISALIGNED                     0x00000040U    /*!< Misaligned address                                            */
#define SDMMC_ERROR_BLOCK_LEN_ERR                       0x00000080U    /*!< Transferred block length is not allowed for the card or the
                                                                            number of transferred bytes does not match the block length   */
#define SDMMC_ERROR_ERASE_SEQ_ERR                       0x00000100U    /*!< An error in the sequence of erase command occurs              */
#define SDMMC_ERROR_BAD_ERASE_PARAM                     0x00000200U    /*!< An invalid selection for erase groups                         */
#define SDMMC_ERROR_WRITE_PROT_VIOLATION                0x00000400U    /*!< Attempt to program a write protect block                      */
#define SDMMC_ERROR_LOCK_UNLOCK_FAILED                  0x00000800U    /*!< Sequence or password error has been detected in unlock
                                                                            command or if there was an attempt to access a locked card    */
#define SDMMC_ERROR_COM_CRC_FAILED                      0x00001000U    /*!< CRC check of the previous command failed                      */
#define SDMMC_ERROR_ILLEGAL_CMD                         0x00002000U    /*!< Command is not legal for the card state                       */
#define SDMMC_ERROR_CARD_ECC_FAILED                     0x00004000U    /*!< Card internal ECC was applied but failed to correct the data  */
#define SDMMC_ERROR_CC_ERR                              0x00008000U    /*!< Internal card controller error                                */
#define SDMMC_ERROR_GENERAL_UNKNOWN_ERR                 0x00010000U    /*!< General or unknown error                                      */
#define SDMMC_ERROR_STREAM_READ_UNDERRUN                0x00020000U    /*!< The card could not sustain data reading in stream rmode       */
#define SDMMC_ERROR_STREAM_WRITE_OVERRUN                0x00040000U    /*!< The card could not sustain data programming in stream mode    */
#define SDMMC_ERROR_CID_CSD_OVERWRITE                   0x00080000U    /*!< CID/CSD overwrite error                                       */
#define SDMMC_ERROR_WP_ERASE_SKIP                       0x00100000U    /*!< Only partial address space was erased                         */
#define SDMMC_ERROR_CARD_ECC_DISABLED                   0x00200000U    /*!< Command has been executed without using internal ECC          */
#define SDMMC_ERROR_ERASE_RESET                         0x00400000U    /*!< Erase sequence was cleared before executing because an out
                                                                            of erase sequence command was received                        */
#define SDMMC_ERROR_AKE_SEQ_ERR                         0x00800000U    /*!< Error in sequence of authentication                           */
#define SDMMC_ERROR_INVALID_VOLTRANGE                   0x01000000U    /*!< Error in case of invalid voltage range                        */
#define SDMMC_ERROR_ADDR_OUT_OF_RANGE                   0x02000000U    /*!< Error when addressed block is out of range                    */
#define SDMMC_ERROR_REQUEST_NOT_APPLICABLE              0x04000000U    /*!< Error when command request is not applicable                  */
#define SDMMC_ERROR_INVALID_PARAMETER                   0x08000000U    /*!< the used parameter is not valid                               */
#define SDMMC_ERROR_UNSUPPORTED_FEATURE                 0x10000000U    /*!< Error when feature is not insupported                         */
#define SDMMC_ERROR_BUSY                                0x20000000U    /*!< Error when transfer process is busy                           */
#define SDMMC_ERROR_DMA                                 0x40000000U    /*!< Error while DMA transfer                                      */
#define SDMMC_ERROR_TIMEOUT                             0x80000000U    /*!< Timeout error                                                 */

/**
  * @brief SDMMC Commands Index
  */
#define SDMMC_CMD_GO_IDLE_STATE                                 0U    /*!< Resets the SD memory card.                                                               */
#define SDMMC_CMD_SEND_OP_COND                                  1U    /*!< Sends host capacity support information and activates the card's initialization process. */
#define SDMMC_CMD_ALL_SEND_CID                                  2U    /*!< Asks any card connected to the host to send the CID numbers on the CMD line.             */
#define SDMMC_CMD_SET_REL_ADDR                                  3U    /*!< Asks the card to publish a new relative address (RCA).                                   */
#define SDMMC_CMD_SET_DSR                                       4U    /*!< Programs the DSR of all cards.                                                           */
#define SDMMC_CMD_SDMMC_SEN_OP_COND                             5U    /*!< Sends host capacity support information (HCS) and asks the accessed card to send its
                                                                           operating condition register (OCR) content in the response on the CMD line.              */
#define SDMMC_CMD_HS_SWITCH                                     6U    /*!< Checks switchable function (mode 0) and switch card function (mode 1).                   */
#define SDMMC_CMD_SEL_DESEL_CARD                                7U    /*!< Selects the card by its own relative address and gets deselected by any other address    */
#define SDMMC_CMD_HS_SEND_EXT_CSD                               8U    /*!< Sends SD Memory Card interface condition, which includes host supply voltage information
                                                                           and asks the card whether card supports voltage.                                         */
#define SDMMC_CMD_SEND_CSD                                      9U    /*!< Addressed card sends its card specific data (CSD) on the CMD line.                       */
#define SDMMC_CMD_SEND_CID                                      10U   /*!< Addressed card sends its card identification (CID) on the CMD line.                      */
#define SDMMC_CMD_READ_DAT_UNTIL_STOP                           11U   /*!< SD card doesn't support it.                                                              */
#define SDMMC_CMD_STOP_TRANSMISSION                             12U   /*!< Forces the card to stop transmission.                                                    */
#define SDMMC_CMD_SEND_STATUS                                   13U   /*!< Addressed card sends its status register.                                                */
#define SDMMC_CMD_HS_BUSTEST_READ                               14U   /*!< Reserved                                                                                 */
#define SDMMC_CMD_GO_INACTIVE_STATE                             15U   /*!< Sends an addressed card into the inactive state.                                         */
#define SDMMC_CMD_SET_BLOCKLEN                                  16U   /*!< Sets the block length (in bytes for SDSC) for all following block commands
                                                                           (read, write, lock). Default block length is fixed to 512 Bytes. Not effective
                                                                           for SDHS and SDXC.                                                                       */
#define SDMMC_CMD_READ_SINGLE_BLOCK                             17U   /*!< Reads single block of size selected by SET_BLOCKLEN in case of SDSC, and a block of
                                                                           fixed 512 bytes in case of SDHC and SDXC.                                                */
#define SDMMC_CMD_READ_MULT_BLOCK                               18U   /*!< Continuously transfers data blocks from card to host until interrupted by
                                                                           STOP_TRANSMISSION command.                                                               */
#define SDMMC_CMD_HS_BUSTEST_WRITE                              19U   /*!< 64 bytes tuning pattern is sent for SDR50 and SDR104.                                    */
#define SDMMC_CMD_WRITE_DAT_UNTIL_STOP                          20U   /*!< Speed class control command.                                                             */
#define SDMMC_CMD_SET_BLOCK_COUNT                               23U   /*!< Specify block count for CMD18 and CMD25.                                                 */
#define SDMMC_CMD_WRITE_SINGLE_BLOCK                            24U   /*!< Writes single block of size selected by SET_BLOCKLEN in case of SDSC, and a block of
                                                                           fixed 512 bytes in case of SDHC and SDXC.                                                */
#define SDMMC_CMD_WRITE_MULT_BLOCK                              25U   /*!< Continuously writes blocks of data until a STOP_TRANSMISSION follows.                    */
#define SDMMC_CMD_PROG_CID                                      26U   /*!< Reserved for manufacturers.                                                              */
#define SDMMC_CMD_PROG_CSD                                      27U   /*!< Programming of the programmable bits of the CSD.                                         */
#define SDMMC_CMD_SET_WRITE_PROT                                28U   /*!< Sets the write protection bit of the addressed group.                                    */
#define SDMMC_CMD_CLR_WRITE_PROT                                29U   /*!< Clears the write protection bit of the addressed group.                                  */
#define SDMMC_CMD_SEND_WRITE_PROT                               30U   /*!< Asks the card to send the status of the write protection bits.                           */
#define SDMMC_CMD_SD_ERASE_GRP_START                            32U   /*!< Sets the address of the first write block to be erased. (For SD card only).              */
#define SDMMC_CMD_SD_ERASE_GRP_END                              33U   /*!< Sets the address of the last write block of the continuous range to be erased.           */
#define SDMMC_CMD_ERASE_GRP_START                               35U   /*!< Sets the address of the first write block to be erased. Reserved for each command
                                                                           system set by switch function command (CMD6).                                            */
#define SDMMC_CMD_ERASE_GRP_END                                 36U   /*!< Sets the address of the last write block of the continuous range to be erased.
                                                                           Reserved for each command system set by switch function command (CMD6).                  */
#define SDMMC_CMD_ERASE                                         38U   /*!< Reserved for SD security applications.                                                   */
#define SDMMC_CMD_FAST_IO                                       39U   /*!< SD card doesn't support it (Reserved).                                                   */
#define SDMMC_CMD_GO_IRQ_STATE                                  40U   /*!< SD card doesn't support it (Reserved).                                                   */
#define SDMMC_CMD_LOCK_UNLOCK                                   42U   /*!< Sets/resets the password or lock/unlock the card. The size of the data block is set by
                                                                           the SET_BLOCK_LEN command.                                                               */
#define SDMMC_CMD_APP_CMD                                       55U   /*!< Indicates to the card that the next command is an application specific command rather
                                                                           than a standard command.                                                                 */
#define SDMMC_CMD_GEN_CMD                                       56U   /*!< Used either to transfer a data block to the card or to get a data block from the card
                                                                           for general purpose/application specific commands.                                       */
#define SDMMC_CMD_NO_CMD                                        64U   /*!< No command                                                                               */

/**
  * @brief Following commands are SD Card Specific commands.
  *        SDMMC_APP_CMD should be sent before sending these commands.
  */
#define SDMMC_CMD_APP_SD_SET_BUSWIDTH                           6U    /*!< (ACMD6) Defines the data bus width to be used for data transfer. The allowed data bus
                                                                            widths are given in SCR register.                                                       */
#define SDMMC_CMD_SD_APP_STATUS                                 13U   /*!< (ACMD13) Sends the SD status.                                                            */
#define SDMMC_CMD_SD_APP_SEND_NUM_WRITE_BLOCKS                  22U   /*!< (ACMD22) Sends the number of the written (without errors) write blocks. Responds with
                                                                           32bit+CRC data block.                                                                    */
#define SDMMC_CMD_SD_APP_OP_COND                                41U   /*!< (ACMD41) Sends host capacity support information (HCS) and asks the accessed card to
                                                                           send its operating condition register (OCR) content in the response on the CMD line.     */
#define SDMMC_CMD_SD_APP_SET_CLR_CARD_DETECT                    42U   /*!< (ACMD42) Connect/Disconnect the 50 KOhm pull-up resistor on CD/DAT3 (pin 1) of the card  */
#define SDMMC_CMD_SD_APP_SEND_SCR                               51U   /*!< Reads the SD Configuration Register (SCR).                                               */
#define SDMMC_CMD_SDMMC_RW_DIRECT                               52U   /*!< For SD I/O card only, reserved for security specification.                               */
#define SDMMC_CMD_SDMMC_RW_EXTENDED                             53U   /*!< For SD I/O card only, reserved for security specification.                               */

/**
  * @brief Following commands are SD Card Specific security commands.
  *        SDMMC_CMD_APP_CMD should be sent before sending these commands.
  */
#define SDMMC_CMD_SD_APP_GET_MKB                                43U
#define SDMMC_CMD_SD_APP_GET_MID                                44U
#define SDMMC_CMD_SD_APP_SET_CER_RN1                            45U
#define SDMMC_CMD_SD_APP_GET_CER_RN2                            46U
#define SDMMC_CMD_SD_APP_SET_CER_RES2                           47U
#define SDMMC_CMD_SD_APP_GET_CER_RES1                           48U
#define SDMMC_CMD_SD_APP_SECURE_READ_MULTIPLE_BLOCK             18U
#define SDMMC_CMD_SD_APP_SECURE_WRITE_MULTIPLE_BLOCK            25U
#define SDMMC_CMD_SD_APP_SECURE_ERASE                           38U
#define SDMMC_CMD_SD_APP_CHANGE_SECURE_AREA                     49U
#define SDMMC_CMD_SD_APP_SECURE_WRITE_MKB                       48U

/**
  * @brief  Masks for errors Card Status R1 (OCR Register)
  */
#define SDMMC_OCR_ADDR_OUT_OF_RANGE                   0x80000000U
#define SDMMC_OCR_ADDR_MISALIGNED                     0x40000000U
#define SDMMC_OCR_BLOCK_LEN_ERR                       0x20000000U
#define SDMMC_OCR_ERASE_SEQ_ERR                       0x10000000U
#define SDMMC_OCR_BAD_ERASE_PARAM                     0x08000000U
#define SDMMC_OCR_WRITE_PROT_VIOLATION                0x04000000U
#define SDMMC_OCR_LOCK_UNLOCK_FAILED                  0x01000000U
#define SDMMC_OCR_COM_CRC_FAILED                      0x00800000U
#define SDMMC_OCR_ILLEGAL_CMD                         0x00400000U
#define SDMMC_OCR_CARD_ECC_FAILED                     0x00200000U
#define SDMMC_OCR_CC_ERROR                            0x00100000U
#define SDMMC_OCR_GENERAL_UNKNOWN_ERROR               0x00080000U
#define SDMMC_OCR_STREAM_READ_UNDERRUN                0x00040000U
#define SDMMC_OCR_STREAM_WRITE_OVERRUN                0x00020000U
#define SDMMC_OCR_CID_CSD_OVERWRITE                   0x00010000U
#define SDMMC_OCR_WP_ERASE_SKIP                       0x00008000U
#define SDMMC_OCR_CARD_ECC_DISABLED                   0x00004000U
#define SDMMC_OCR_ERASE_RESET                         0x00002000U
#define SDMMC_OCR_AKE_SEQ_ERROR                       0x00000008U
#define SDMMC_OCR_ERRORBITS                           0xFDFFE008U

/**
  * @brief  Masks for R6 Response
  */
#define SDMMC_R6_GENERAL_UNKNOWN_ERROR                0x00002000U
#define SDMMC_R6_ILLEGAL_CMD                          0x00004000U
#define SDMMC_R6_COM_CRC_FAILED                       0x00008000U

#define SDMMC_VOLTAGE_WINDOW_SD                       0x80100000U
#define SDMMC_HIGH_CAPACITY                           0x40000000U
#define SDMMC_STD_CAPACITY                            0x00000000U
#define SDMMC_CHECK_PATTERN                           0x000001AAU
#define SD_SWITCH_1_8V_CAPACITY                       0x01000000U

#define SDMMC_MAX_VOLT_TRIAL                          0x0000FFFFU

#define SDMMC_MAX_TRIAL                               0x0000FFFFU

#define SDMMC_ALLZERO                                 0x00000000U

#define SDMMC_WIDE_BUS_SUPPORT                        0x00040000U
#define SDMMC_SINGLE_BUS_SUPPORT                      0x00010000U
#define SDMMC_CARD_LOCKED                             0x02000000U

#ifndef SDMMC_DATATIMEOUT
#define SDMMC_DATATIMEOUT                             0xFFFFFFFFU
#endif /* SDMMC_DATATIMEOUT */

#define SDMMC_0TO7BITS                                0x000000FFU
#define SDMMC_8TO15BITS                               0x0000FF00U
#define SDMMC_16TO23BITS                              0x00FF0000U
#define SDMMC_24TO31BITS                              0xFF000000U
#define SDMMC_MAX_DATA_LENGTH                         0x01FFFFFFU

#define SDMMC_HALFFIFO                                0x00000008U
#define SDMMC_HALFFIFOBYTES                           0x00000020U

#define SDIO_RESPONSE_NO                    0x00000000U
#define SDIO_RESPONSE_SHORT                 SDIO_CMD_WAITRESP_0
#define SDIO_RESPONSE_LONG                  SDIO_CMD_WAITRESP

#define SDIO_WAIT_NO                        0x00000000U
#define SDIO_WAIT_IT                        SDIO_CMD_WAITINT
#define SDIO_WAIT_PEND                      SDIO_CMD_WAITPEND

#define SDIO_CPSM_DISABLE                   0x00000000U
#define SDIO_CPSM_ENABLE                    SDIO_CMD_CPSMEN

#define SDIO_FLAG_CCRCFAIL                  SDIO_STA_CCRCFAIL
#define SDIO_FLAG_DCRCFAIL                  SDIO_STA_DCRCFAIL
#define SDIO_FLAG_CTIMEOUT                  SDIO_STA_CTIMEOUT
#define SDIO_FLAG_DTIMEOUT                  SDIO_STA_DTIMEOUT
#define SDIO_FLAG_TXUNDERR                  SDIO_STA_TXUNDERR
#define SDIO_FLAG_RXOVERR                   SDIO_STA_RXOVERR
#define SDIO_FLAG_CMDREND                   SDIO_STA_CMDREND
#define SDIO_FLAG_CMDSENT                   SDIO_STA_CMDSENT
#define SDIO_FLAG_DATAEND                   SDIO_STA_DATAEND
#define SDIO_FLAG_STBITERR                  SDIO_STA_STBITERR
#define SDIO_FLAG_DBCKEND                   SDIO_STA_DBCKEND
#define SDIO_FLAG_CMDACT                    SDIO_STA_CMDACT
#define SDIO_FLAG_TXACT                     SDIO_STA_TXACT
#define SDIO_FLAG_RXACT                     SDIO_STA_RXACT
#define SDIO_FLAG_TXFIFOHE                  SDIO_STA_TXFIFOHE
#define SDIO_FLAG_RXFIFOHF                  SDIO_STA_RXFIFOHF
#define SDIO_FLAG_TXFIFOF                   SDIO_STA_TXFIFOF
#define SDIO_FLAG_RXFIFOF                   SDIO_STA_RXFIFOF
#define SDIO_FLAG_TXFIFOE                   SDIO_STA_TXFIFOE
#define SDIO_FLAG_RXFIFOE                   SDIO_STA_RXFIFOE
#define SDIO_FLAG_TXDAVL                    SDIO_STA_TXDAVL
#define SDIO_FLAG_RXDAVL                    SDIO_STA_RXDAVL
#define SDIO_FLAG_SDIOIT                    SDIO_STA_SDIOIT
#define SDIO_FLAG_CEATAEND                  SDIO_STA_CEATAEND


























#endif

#endif /* SDMMC_DEF_H_ */
