#ifndef GBASICTYPE_H
#define GBASICTYPE_H
/*******************************************************************************
       Include            Files
*******************************************************************************/


/* Make this header file easier to include in C++ code */
#ifdef __cplusplus
extern "C" {
#endif
/*******************************************************************************
       Marco             Definition
*******************************************************************************/
/**
    \def TRUE
    Bool value true.
*/
#ifndef TRUE
#define	TRUE	(1)
#endif

/**
    \def FALSE
    Bool value false.
*/
#ifndef FALSE
#define FALSE	(0)
#endif

/**
    \def NULL
    Null pointer.
*/
#ifndef NULL
#define	NULL	((void *)0)
#endif

/**
    \def ARRAY_SIZE(a)
    Element total of array.
    \param[in] a : Array name.
*/
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a)		(sizeof(a)/sizeof(a[0]))
#endif



/**
    \def ZERO
    ZERO value macro..
*/
#ifndef ZERO
#define ZERO 0          /**<define for '0'.*/
#endif

/**
    \def TIMEOUT_NSC
*/
#ifndef TIMEOUT_NSC
#define TIMEOUT_NSC 0
#endif
/*******************************************************************************
    Type Definition
*******************************************************************************/
/**
    \typedef unsigned char uint8
    Unsigned single byte integer type.
*/
typedef unsigned char		uint8;

/**
    \typedef signed char sint8
    Signed single byte integer type.
*/
typedef signed char			sint8;

/**
    \typedef unsigned short int uint16
    Unsigned double bytes integer type.
*/
typedef unsigned short int	uint16;

/**
    \typedef signed short int sint16
    Signed double bytes integer type.
*/
typedef signed short int	sint16;

/**
    \typedef unsigned int uint32
    Unsigned four bytes integer type.
*/
typedef unsigned int		uint32;

/**
    \typedef signed int sint32
    Signed four bytes integer type.
*/
typedef signed int			sint32;

/**
    \typedef unsigned long long	uint64
    Unsigned eight bytes integer type.
*/
typedef unsigned long long	uint64;

/**
    \typedef signed long long	sint64
    Signed eight bytes integer type.
*/
typedef signed long long	sint64;

/**
    \typedef float float32
    Single-precision float type.
*/
typedef float				float32;

/**
    \typedef double float64
    Double-precision float type.
*/
typedef double				float64;


/**
    \typedef char char_t
    Character type.
*/
typedef char				char_t;

/**
    \typedef int bool_t
    bool type.
*/
typedef int bool_t;

/**
     \enum nf_result_e
     callback result of function.
*/
typedef enum {
    G_SUCCESS  = 0,                   /**<Success.                         */
    G_FAILURE,                    /**<False.                           */
    G_NON,                        /**<NON.                             */
    G_ILPARAM,                    /**<Illegal parameter                */
    G_TIMEOUT,                    /**<dbus complete Timeout or other timeout */
    G_NO_SUPPORT,                 /**<process no support or no Interface or other no support */
    G_BUSY,                       /**<Busy                             */
    G_NOMEMORY,                   /**<No memory                             */
    G_NO_REPLY,                   /**<No reply                         */
    G_CATEGORY_FINISH,           /**<Account is not exist                    */
    G_NO_LOGIN,                   /**<Account is not exist                    */
    G_PASSWORD_DISCORD,           /**<password is discord                   */
    G_PINVALID_TYPE,              /**< Data packet format invalid type      */
    G_PINVALID_CHECKSUM,          /**< Data packet format invalid checksum  */
    G_PINVALID_LEN,               /**< Data packet format invalid length    */
    G_PINVALID_CRC,               /**< Data packet format invalid length    */
    G_NO_CONN,                    /**< not connect  */
    G_NO_EVENT,                    /*<send event error                   */
    G_ENDING,                  /*<ending                    */
    G_PREV_CATEGORY_CHG,       /*<send event error                   */
    G_RPC_ERR,                 /*<send event error                   */
    G_DB_ERR,                  /*<send event error                   */
    G_PERM,           /*	不允许操作                 	*/ /*	 Operation not permitted              	*/
    G_NOENT,         	/*	没有这样的文件或目录       	*/ /*	 No such file or directory            	*/
    G_SRCH,          	/*	没有这样的进程             	*/ /*	 No such process                      	*/
    G_IO,            	/*	输入/输出错误              	*/ /*	 Input/output error                   	*/
    G_NXIO,          	/*	没有这样的设备或地址       	*/ /*	 No such device or address            	*/
    G_2BIG,          	/*	参数列表太长了             	*/ /*	 Argument list too long               	*/
    G_FORMAT,        	/*	格式错误                   	*/ /*	 format error                         	*/
    G_BADF ,         	/*	无效文件描述符             	*/ /*	 Bad file descriptor                  	*/
    G_AGAIN,         	/*	资源暂时不可用             	*/ /*	 Resource temporarily unavailable     	*/
    G_NOMEM,         	/*	无法分配内存               	*/ /*	 Cannot allocate memory               	*/
    G_ACCES,         	/*	没有权限                   	*/ /*	 Permission denied                    	*/
    G_FAULT,         	/*	错误地址                   	*/ /*	 Bad address                          	*/
//    G_BUSY,          	/*	设备或资源忙               	*/ /*	 Device or resource busy              	*/
    G_XDEV,          	/*	无效的跨设备的链接         	*/ /*	 Invalid cross-device link            	*/
    G_NODEV,         	/*	没有这样的设备             	*/ /*	 No such device                       	*/
    G_NOTDIR,        	/*	不是一个目录               	*/ /*	 Not a directory                      	*/
    G_INVAL,         	/*	非法参数                   	*/ /*	 Invalid argument                     	*/
    G_NRESOURCES,    	/*	资源已满                   	*/ /*	 Resources is full                    	*/
    G_NOTTY,         	/*	不恰当的控制代码对设备来说 	*/ /*	 Inappropriate ioctl for device       	*/
    G_FBIG,          	/*	文件太大                   	*/ /*	 File too large                       	*/
    G_NOSPC,         	/*	磁盘空间不足               	*/ /*	 No space left on device              	*/
    G_SPIPE,         	/*	非法的搜索                 	*/ /*	 Illegal seek                         	*/
    G_PIPE,           /*	非正常关闭socket引发的错误 	*/ /*	 Broken pipe                          	*/
    G_DOM,           	/*	数值超出定义域             	*/ /*	 Numerical argument out of domain     	*/
    G_RANGE,         	/*	数值结果超出范围           	*/ /*	 Numerical result out of range        	*/
    G_NAMETOOLONG,   	/*	 文件名太长                	*/ /*	 File name too long                   	*/
    G_NOLCK,         	/*	 没有可用的锁              	*/ /*	 No locks available                   	*/
    G_NOSYS,         	/*	 功能没有实现              	*/ /*	 Function not implemented             	*/
    G_NOTEMPTY,      	/*	 目录非空                  	*/ /*	 Directory not empty                  	*/
    G_LOOP,          	/*	 符号链接太多了            	*/ /*	 Too many levels of symbolic links    	*/
    G_NOMSG,         	/*	 没有需要类型的消息        	*/ /*	 No message of desired type           	*/
    G_UNATCH,        	/*	 协议驱动程序不能连接      	*/ /*	 Protocol driver not attached         	*/
    G_BADR,          	/*	 无效的请求描述符          	*/ /*	 Invalid request descriptor           	*/
    G_BADRQC,        	/*	 无效的请求代码            	*/ /*	 Invalid request code                 	*/
    G_BFONT,         	/*	 错误的字体文件格式        	*/ /*	 Bad font file format                 	*/
    G_NODATA,        	/*	 没有数据可用              	*/ /*	 No data available                    	*/
    G_NOPKG,         	/*	 包没有安装                	*/ /*	 Package not installed                	*/
    G_COMM,          	/*	 通信错误发送              	*/ /*	 Communication error on send          	*/
    G_LIBACC,        	/*	 无法访问需要的共享库          */ /*	 Can not access a needed sharedlibrary	*/
    G_NOPROTOOPT,    	/*	 协议不可用                	*/ /*	 Protocol not available               	*/
    G_PROTONOSUPPORT,	/*	 协议不支持                	*/ /*	 Protocol not supported               	*/
    G_ADDRINUSE,     	/*	 地址已在使用              	*/ /*	 Address already in use               	*/
    G_TIMEDOUT,      	/*	连接超时                   	*/ /*	 Connection timed out                 	*/
} nf_result_e;

typedef enum {
    /* 00 */    INDEX_0 = 0,
    /* 01 */    INDEX_1,
    /* 02 */    INDEX_2,
    /* 03 */    INDEX_3,
    /* 04 */    INDEX_4,
    /* 05 */    INDEX_5,
    /* 06 */    INDEX_6,
    /* 07 */    INDEX_7,
    /* 08 */    INDEX_8,
    /* 09 */    INDEX_9,
    /* 10 */    INDEX_10,
    /* 11 */    INDEX_11,
    /* 12 */    INDEX_12,
    /* 13 */    INDEX_13,
    /* 14 */    INDEX_14,
    /* 15 */    INDEX_15,
    /* 16 */    INDEX_16,
    /* 17 */    INDEX_17,
    /* 18 */    INDEX_18,
    /* 19 */    INDEX_19,
    /* 20 */    INDEX_20,
    /* 21 */    INDEX_21,
    /* 22 */    INDEX_22,
    /* 23 */    INDEX_23,
    /* 24 */    INDEX_24,
    /* 25 */    INDEX_25,
    /* 26 */    INDEX_26,
    /* 27 */    INDEX_27,
    /* 28 */    INDEX_28,
    /* 29 */    INDEX_29
} buffer_index_e;

typedef enum {
    /* 00 */    SIZE_0 = 0,
    /* 01 */    SIZE_1,
    /* 02 */    SIZE_2,
    /* 03 */    SIZE_3,
    /* 04 */    SIZE_4,
    /* 05 */    SIZE_5,
    /* 06 */    SIZE_6,
    /* 07 */    SIZE_7,
    /* 08 */    SIZE_8,
    /* 09 */    SIZE_9,
    /* 10 */    SIZE_10,
    /* 11 */    SIZE_11,
    /* 12 */    SIZE_12,
    /* 13 */    SIZE_13,
    /* 14 */    SIZE_14,
    /* 15 */    SIZE_15,
    /* 16 */    SIZE_16,
    /* 17 */    SIZE_17,
    /* 18 */    SIZE_18,
    /* 19 */    SIZE_19,
    /* 20 */    SIZE_20,
    /* 21 */    SIZE_21,
    /* 22 */    SIZE_22,
    /* 23 */    SIZE_23,
    /* 24 */    SIZE_24,
    /* 25 */    SIZE_25,
    /* 26 */    SIZE_26,
    /* 27 */    SIZE_27,
    /* 28 */    SIZE_28,
    /* 29 */    SIZE_29
} buffer_size_e;

typedef enum {
    /* 00 */    VALUE_0 = 0,
    /* 01 */    VALUE_1,
    /* 02 */    VALUE_2,
    /* 03 */    VALUE_3,
    /* 04 */    VALUE_4,
    /* 05 */    VALUE_5,
    /* 06 */    VALUE_6,
    /* 07 */    VALUE_7,
    /* 08 */    VALUE_8,
    /* 09 */    VALUE_9,
    /* 10 */    VALUE_10,
    /* 11 */    VALUE_11,
    /* 12 */    VALUE_12,
    /* 13 */    VALUE_13,
    /* 14 */    VALUE_14,
    /* 15 */    VALUE_15,
    /* 16 */    VALUE_16,
    /* 17 */    VALUE_17,
    /* 18 */    VALUE_18,
    /* 19 */    VALUE_19,
    /* 20 */    VALUE_20,
    /* 21 */    VALUE_21,
    /* 22 */    VALUE_22,
    /* 23 */    VALUE_23,
    /* 24 */    VALUE_24,
    /* 25 */    VALUE_25,
    /* 26 */    VALUE_26,
    /* 27 */    VALUE_27,
    /* 28 */    VALUE_28,
    /* 29 */    VALUE_29
} buffer_value_e;

/*@}*/
#ifdef __cplusplus
}
#endif

#endif // GBASICTYPE_H
