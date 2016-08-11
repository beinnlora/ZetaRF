/*! @file ZetaRF.h
 *
 * @brief This file contains the public functions controlling the Si4455 radio chip.
 */

#ifndef ZETARF_H_
#define ZETARF_H_

#include "si4455_defs.h"

typedef si4455_reply_FIFO_INFO_map      Si4455_FifoInfo;
typedef si4455_reply_GPIO_PIN_CFG_map   Si4455_GpioPinConfig;
typedef si4455_reply_GET_INT_STATUS_map Si4455_InterruptStatus;
typedef si4455_reply_PART_INFO_map      Si4455_PartInfo;
typedef si4455_reply_GET_PROPERTY_map   Si4455_Properties;
typedef si4455_reply_FUNC_INFO_map      Si4455_FuncInfo;

typedef si4455_reply_FRR_A_READ_map     Si4455_FrrA;
typedef si4455_reply_FRR_B_READ_map     Si4455_FrrB;
typedef si4455_reply_FRR_C_READ_map     Si4455_FrrC;
typedef si4455_reply_FRR_D_READ_map     Si4455_FrrD;

typedef si4455_reply_REQUEST_DEVICE_STATE_map   Si4455_DeviceState;
typedef si4455_reply_READ_CMD_BUFF_map          Si4455_CommandBuffer;
typedef si4455_reply_GET_ADC_READING_map        Si4455_AdcReadings;

typedef si4455_reply_GET_PH_STATUS_map      Si4455_PhStatus;
typedef si4455_reply_GET_MODEM_STATUS_map   Si4455_ModemStatus;
typedef si4455_reply_GET_CHIP_STATUS_map    Si4455_ChipStatus;

typedef si4455_reply_PACKET_INFO_map    Si4455_PacketInfo;


class ZetaRF
{
public:
    ZetaRF(int csPin, int shutdownPin, int irqPin);

    bool begin(uint8_t channel = 0, uint8_t packetLength = 0 /* 0 = default packet length defined by ZETARF_PACKET_LENGTH*/);

    void setChannel(uint8_t channel);

    void sendPacket(const uint8_t *data);
    void sendPacket(const uint8_t *data, uint8_t length);
    void sendPacket(uint8_t channel, const uint8_t *data);
    void sendPacket(uint8_t channel, const uint8_t *data, uint8_t length);

    void startListening();
    void startListening(uint8_t channel);
    void startListening(uint8_t channel, uint8_t length);

    bool checkTransmitted();
    bool checkReceived();

    uint8_t readPacket(uint8_t *data);


    bool isTxFifoAlmostEmpty();
    bool isRxFifoAlmostFull();

    const Si4455_PartInfo& readPartInfo();
    const Si4455_FuncInfo& readFuncInfo();
    
private:
    enum CommandResult
    {
        Success,
        NoPatch,
        CtsTimeout,
        PatchFail,
        CommandError
    };

    typedef si4455_cmd_reply_union CommandReply;

    void powerUp();

    void reset();
    CommandResult initialize(const uint8_t* configArray);

    void writeEZConfigArray(const uint8_t* ezConfigArray, uint8_t count);
    uint8_t checkEZConfig(uint16_t checksum);

    void startTx(uint8_t channel, uint8_t condition, uint16_t length);
    void writeTxFifo(const uint8_t* data, uint8_t length);

    void startRx(uint8_t channel, uint8_t condition, uint16_t length, uint8_t nextState1, uint8_t nextState2, uint8_t nextState3);
    void readRxFifo(uint8_t* data, uint8_t length);

    Si4455_InterruptStatus& readInterruptStatus(uint8_t clearPendingPH, uint8_t clearPendingModem, uint8_t clearPendingChip);

    Si4455_GpioPinConfig& configureGpioPins(uint8_t gpio0, uint8_t gpio1, uint8_t gpio2, uint8_t gpio3, uint8_t nirq, uint8_t sdo, uint8_t genConfig);
    
    Si4455_Properties& readProperties(uint8_t group, uint8_t count, uint8_t startProperty);
    void setProperties(uint8_t group, uint8_t count, uint8_t property, ...);

    Si4455_DeviceState& requestDeviceState();
    void changeState(uint8_t nextState1);

    void nopCommand();

    
    Si4455_FifoInfo& readFifoInfo(uint8_t fifo = 0);
    void resetFifo();
    Si4455_PacketInfo& readPacketInfo(uint8_t fieldNum, uint16_t len, uint16_t lenDiff);
    // @todo Add PacketInfo read
    
    Si4455_FrrA& readFrrA(uint8_t count);
    Si4455_FrrB& readFrrB(uint8_t count);
    Si4455_FrrC& readFrrC(uint8_t count);
    Si4455_FrrD& readFrrD(uint8_t count);
    
    Si4455_CommandBuffer& readCommandBuffer();

    Si4455_AdcReadings& readADC(uint8_t adcEnable, uint8_t adcConfig);

    Si4455_PhStatus& readPhStatus(uint8_t clearPendingPH);
    Si4455_ModemStatus& readModemStatus(uint8_t clearPendingModem);
    Si4455_ChipStatus& readChipStatus(uint8_t clearPendingChip);



    uint8_t getResponse(uint8_t* data, uint8_t count);
    void sendCommand(const uint8_t* data, uint8_t count);
    uint8_t sendCommandAndGetResponse(const uint8_t* commandData, uint8_t commandByteCount, uint8_t* responseData, uint8_t responseByteCount);

    void readData(uint8_t command, uint8_t* data, uint8_t count, bool pollCtsFlag);
    void writeData(uint8_t command, const uint8_t* data, uint8_t count, bool pollCtsFlag);

    uint8_t pollCts();
    void clearCts();


    void assertShutdown() const;
    void deassertShutdown() const;
    void clearCS() const;
    void setCS() const;
    bool irqLevel() const;

    uint8_t spiReadWriteByte(uint8_t value) const;
    void spiWriteByte(uint8_t value) const;
    uint8_t spiReadByte() const;


    void spiReadWriteData(uint8_t* data, uint8_t count) const;
    void spiWriteData(const uint8_t* data, uint8_t count) const;
    void spiReadData(uint8_t* data, uint8_t count) const;


    const int m_csPin;
    const int m_sdnPin;
    const int m_irqPin;
    bool m_ctsWentHigh;

    si4455_cmd_reply_union m_commandReply;

    uint8_t m_channelNumber;
    uint8_t m_packetLength;

    bool m_dataTransmittedFlag;
    bool m_dataAvailableFlag;
    bool m_crcErrorFlag;    // @todo Add getter
    bool m_txFifoAlmostEmptyFlag;
    bool m_rxFifoAlmostFullFlag;

    const uint8_t *m_radioConfigurationDataArray;
};

#endif /* ZETARF_H_ */
