/*! @file : K32L2B31A_Project.c
 * @author  Ernesto Andres Rincon Cruz
 * @version 0.0.000
 * @date    23/08/2021
 * @brief   Funcion principal main
 * @details
 *			v0.0.000	Proyecto base creado usando MCUXpresso
 *
 *
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "K32L2B31A.h"
#include "fsl_debug_console.h"
#include <limits.h>
#include <float.h>

#include <iot_sdk_peripherals_leds.h>
#include <iot_sdk_peripherals_light.h>
#include "iot_sdk_peripherals_buttons.h"
#include "iot_sdk_peripheral_temperature.h"

#include "iot_sdk_ irq_lptimer0.h"
#include "iot_sdk_irq_lpuart0.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
enum list_comandos_at {
	kAT = 0,
	kATI,
	kAT_CPIN,
	kAT_CSQ,
	kAT_QCSQ,
	kAT_CREG,
	kAT_CGREG,
	kAT_QIACT1,
	kesperando_respuesta,
};

enum Comandos_ledsensor {
	kLED_VERDE_ON = 0,
	kLED_VERDE_OFF,
	kLED_ROJO_ON,
	kLED_ROJO_OFF,
	kSENSOR_LUX,
	kSENSOR_TEMP,
};

#define COMANDOS_DISPONIBLES_LEDS_SENSOR 6
#define COMANDOS_DISPONIBLES_AT 10
#define BYTES_EN_BUFFER	100


/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/
void esperando_respuesta(void);
/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Local vars
 ******************************************************************************/
const char *comandos_at[] = {
    		    "AT",
    			"ATI",
    			"AT+CPIN?",
				"AT+CSQ",
    			"AT+QCSQ",
    			"AT+CREG?",
    			"AT+CGREG?",
				"AT+QIACT=1"
    	};

    //Lista de respuestas a cada comando AT
    const char  *repuestas_at[]={
    		        "OK",		//AT
    				"EC200T",		//ATI
    				"READY",	//AT+CPIN?
					"+CSQ:",		//AT+CSQ
    				"LTE",    //AT+QCSQ
    				"0,1",		//AT+CREG? = GSM,REGISTERED
    				"0,1", //AT+CGREG?
    				"OK",  //AT+QIACT=1
    };

    const char  *repuestas_LEDS[]={
       		        "ENCENDER LED VERDE",		//AT
       				"APAGAR LED VERDE",		//ATI
       				"ENCENDER LED ROJO",	//AT+CPIN?
       				"APAGAR LED ROJO",
					"LECTURA_LUM",
					"LECTURA_TEMP"

       };


    uint8_t buffer_rx[BYTES_EN_BUFFER];		//almacena las datos que provienen del modem
    uint8_t index_buffer_rx = 0;				//apuntador de buffer de datos


/*******************************************************************************
 * Private Source Code
 ******************************************************************************/

    void BorrarBufferRX(void){
        	uint8_t i;

        	//LLenar de ceros buffer que va a recibir datos provenientes del modem
        	for(i=0;i<BYTES_EN_BUFFER;i++){
        		buffer_rx[i]=0;
        	}

        	//borra apuntador de posicion donde se va a almacenar el proximo dato
        	//Reset al apuntador
        	index_buffer_rx=0;
        }


 int main(void) {
	
}
