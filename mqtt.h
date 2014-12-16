typedef struct
{
	BYTE DATA[1501];
	DWORD IPOS;
}
BUFFERtyp;

typedef struct
{
	BYTE BMESSAGETYPE;
	BOOL XDUP_FLAG;
	BYTE XQOS;
	BOOL XRETAIN;
}
FIXEDHEADERtyp;

typedef struct
{
	BOOL XUSERNAME;
	BOOL XPASSWORD;
	BOOL XWILLRETAIN;
	BOOL XWILLQOS1;
	BOOL XWILLQOS2;
	BOOL XWILLFLAG;
	BOOL XCLEANSESSION;
}
CONNECTFLAGStyp;

typedef struct
{
	BYTE VERSION;
	BYTE RESERVED;
	BYTE CONNECT;
	BYTE CONNACK;
	BYTE PUBLISH;
	BYTE PUBACK;
	BYTE PUBREC;
	BYTE PUBREL;
	BYTE PUBCOMP;
	BYTE SUBSCRIBE;
	BYTE SUBACK;
	BYTE UNSUBSCRIBE;
	BYTE UNSUBACK;
	BYTE PINGREQ;
	BYTE PINGRESP;
	BYTE DISCONNECT;
	BYTE RESERVED2;
	INT CONNECTED;
	INT NOT_CONNECTED;
	INT TIMEOUT;
	INT WAIT_RESPONSE;
	DWORD CONNECTION_TIMEOUT;
	BUFFERtyp SENDBUFFER;
	BUFFERtyp RECEIVEBUFFER;
	FIXEDHEADERtyp FIXEDHEADER;
	BUFFERtyp VARIABLEHEADER;
	BUFFERtyp PAYLOAD;
	CONNECTFLAGStyp CONNECTFLAGS;
	TCP_CLIENTtyp TCPCLIENT;
	BOOL XTCPCONNECTED;
	BOOL XSTARTSEND;
	DINT DIRECEIVECOUNT;
	TONtyp CONNECTIONTIMER;
	BOOL XTIMEOUT;
	BYTE INCOMINGMESSAGETYPE;
	INT ESTATE;
	BOOL XSTARTTIMER;
	char STOPIC[81];
	char SPAYLOAD[81];
	BOOL XCONNECTED;
	BOOL *XPUBLISH;
	BOOL *XSUBSCRIBE;
}
MQTT_CLIENTtyp;


/* Enum definitions */


/* The Prototypes */
BOOL BUFFERinit(BUFFERtyp* inst, BOOL bRetain);
BOOL _BUFFER_CONCAT(BUFFERtyp *PTparam, BUFFERtyp *PTCONTACTparam);
;
BOOL _BUFFER_PUSH(BUFFERtyp *PTparam, BYTE INparam);
;
BOOL _BUFFER_PUSH_STRING(BUFFERtyp *PTparam, char* INparam, BOOL INCLUDE_LENGTHparam);
;
BOOL _BUFFER_SET(BUFFERtyp *PTparam, BYTE INparam, WORD POSparam);
;
BOOL FIXEDHEADERinit(FIXEDHEADERtyp* inst, BOOL bRetain);
BOOL CREATE_MESSAGE(BUFFERtyp *PTparam, FIXEDHEADERtyp FIXEDHEADERparam, BUFFERtyp VARIABLEHEADERparam, BUFFERtyp PAYLOADparam);
;
BOOL ENCODE_REMAINING_LENGTH(BUFFERtyp *PTparam, DWORD LENGTHparam);
;
BOOL CONNECTFLAGSinit(CONNECTFLAGStyp* inst, BOOL bRetain);
void MQTT_CLIENT(MQTT_CLIENTtyp* inst);
BOOL MQTT_CLIENTinit(MQTT_CLIENTtyp* inst, BOOL bRetain);
void PLC_PRG(void);
;