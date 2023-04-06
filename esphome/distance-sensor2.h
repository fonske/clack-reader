#include "esphome.h"
using namespace esphome;
 
enum statesRX
{
    ST_RX_HEADER=0,
    ST_RX_DATA,
    ST_RX_PROCESSMSG    
};

unsigned char data[4]={};
//float distance;
  
class DistanceSensor : public PollingComponent, public sensor::Sensor, public UARTDevice{
 public:
    DistanceSensor(uint32_t update_interval, UARTComponent *parent) : PollingComponent(update_interval), UARTDevice(parent) {}

    void setup() override{};

    void update() override {
    static uint8_t
        stateRX = ST_RX_HEADER,
        rxIdx;
        
    if( available() > 0 )
    {
        do
        {
            uint8_t ch = read(); 
            switch( stateRX )
            {
                case    ST_RX_HEADER:
                    if( ch == 0xff )
                    {
                        rxIdx = 0;
                        data[rxIdx++] = ch;
                        stateRX = ST_RX_DATA;
                        
                    }//if
                    
                break; 

                case    ST_RX_DATA:
                    data[rxIdx++] = ch;
                    if( rxIdx == 4 )
                        stateRX = ST_RX_PROCESSMSG;
                break;

                case    ST_RX_PROCESSMSG:
                    uint8_t sum = 0;
                    for( uint8_t i=0; i<3; i++ )
                        sum = sum + data[i];

                    if( sum == data[3] )
                    {
                        uint16_t distance = ((uint16_t)data[1] << 8) + data[2];
                        if( distance > 30 )
                        {
                            publish_state(distance/10);
                        }//if
                        else
                            ESP_LOGD("custom", "Distance below lower limit.");     
                        
                    }//if
                    else
                        ESP_LOGD("custom", "Msg checksum error.");

                    stateRX = ST_RX_HEADER;
                    
                break;
                
            }//switch
            
        }while( available() > 0 );
        
    }//if
    
  }//loop
};

