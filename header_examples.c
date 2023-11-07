// Some macros for the header file

// Add the endianness detection and definitions here
#if defined(__linux__)
    #include <endian.h>
    #ifndef LITTLE_ENDIAN
        #define LITTLE_ENDIAN __LITTLE_ENDIAN
    #endif
    #ifndef BIG_ENDIAN
        #define BIG_ENDIAN __BIG_ENDIAN
    #endif
    #ifndef BYTE_ORDER
        #define BYTE_ORDER __BYTE_ORDER
    #endif
#elif defined(__QNXNTO__)
    #include <sys/byteorder.h>
    #ifndef LITTLE_ENDIAN
        #define LITTLE_ENDIAN _LITTLE_ENDIAN
    #endif
    #ifndef BIG_ENDIAN
        #define BIG_ENDIAN _BIG_ENDIAN
    #endif
    #ifndef BYTE_ORDER
        #define BYTE_ORDER _BYTE_ORDER
    #endif
// You can add more platform-specific cases here if needed
#else
    #error "Platform not supported"
#endif

// The logic for bitshifting
uint64_t largeCounter = /* your 64-bit counter value */;
CounterStruct myCounter;

#if BYTE_ORDER == BIG_ENDIAN
    myCounter.threeByteCounter[0] = (largeCounter >> 40) & 0xFF;
    myCounter.threeByteCounter[1] = (largeCounter >> 32) & 0xFF;
    myCounter.threeByteCounter[2] = (largeCounter >> 24) & 0xFF;
#elif BYTE_ORDER == LITTLE_ENDIAN
    myCounter.threeByteCounter[0] = (largeCounter >> 16) & 0xFF;
    myCounter.threeByteCounter[1] = (largeCounter >> 8) & 0xFF;
    myCounter.threeByteCounter[2] = largeCounter & 0xFF;
#else
    // Handle error or set to zero if you want to ignore endianness issues.
    myCounter.threeByteCounter[0] = 0;
    myCounter.threeByteCounter[1] = 0;
    myCounter.threeByteCounter[2] = 0;
#endif