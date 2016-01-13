#pragma once

//-----------------------------------------------------------------------------
// defaults
#define     DEFAULT_LANGUAGE                    "Deutsch"
#define     DEFAULT_SCREENSAVER_TIMEOUT         "10"        //in minuten
#define     DEFAULT_OPERATING_TIMEOUT           "10"        //in minuten
#define     DEFAULT_DEVICE_COLOR_THEME          "0"
#define     DEFAULT_DEVICE_TEMPCORR             "0.0"
#define     DEFAULT_DEVICE_HUMCORR              "0.0"
#define     DEFAULT_CTRLPASSWORD_RESEND_DELAY   "15"        //in minuten
#define     DEFAULT_PROCDATARECORDER_STATE      "1"         //aufzeichnung eingeschalten
#define     DEFAULT_TFTCONTRAST                 "50"
#define     DEFAULT_TEMP_SCALA                  "0"
#define     DEFAULT_DATE_FORMAT                 "dd.MM.yyyy"
#define     DEFAULT_TIME_FORMAT                 "hh:mm"
#define     DEFAULT_ZONE_MAPPING                "0"
#define     DEFAULT_DEFAULT_CIRCUIT             "1"
#ifdef DESKTOP
#define     DEFAULT_LOGDIR_RECDATA              "var/ldata"
#define     DEFAULT_LOGDIR_PROCDATA             "var/pdata"
#else
#define     DEFAULT_LOGDIR_RECDATA              "/media/sdcard/ldata"
#define     DEFAULT_LOGDIR_PROCDATA             "/var/pdata"
#endif //DESKTOP
#define     DEFAULT_TARGET_UNITNR               "2"     //masterregler
#define     DEFAULT_TARGET_CIRCUIT              "4"     // heizkreis 1

//-----------------------------------------------------------------------------
// Keys und sections
#define     CONFIGFILE_SETTINGS                     "Settings/"
#define     CONFIGFILE_ACTUAL_LANGUAGE              "Language"
#define     CONFIGFILE_SCREENSAVER_TIMEOUT          "ScreenSaverTimeout"
#define     CONFIGFILE_OPERATING_TIMEOUT            "OperatingTimeout"
#define     CONFIGFILE_DEVICE_THEME                 "ColorTheme"
#define     CONFIGFILE_DEVICE_TEMPCORR              "TempCorrection"
#define     CONFIGFILE_DEVICE_HUMCORR               "HumCorrection"
#define     CONFIGFILE_CTRLPWD_RESEND_DELAY         "CtrlPwdResendDelay"
#define     CONFIGFILE_PROCDATA_RECORDING           "RecProcData"
#define     CONFIGFILE_TFT_CONTRAST                 "TFTContrast"
#define     CONFIGFILE_TEMP_SCALA                   "TempScala"
#define     CONFIGFILE_TIME_FORMAT                  "TimeFormat"
#define     CONFIGFILE_DATE_FORMAT                  "DateFormat"
#define     CONFIGFILE_ZONEMAPPING                  "ZoneMapping"
#define     CONFIGFILE_DEFAULT_CIRCUIT              "DefaultCircuit"

#define     CONFIGFILE_WSRC7000_SETTINGS            "WsRC7000/"
#define     CONFIGFILE_LOG_DIRECTORY_RECDATA        "recdata"
#define     CONFIGFILE_LOG_DIRECTORY_PROCDATA       "procdata"

#define     CONFIGFILE_TARGET                       "Target/"
#define     CONFIGFILE_ACTIVE_TARGET_UNITNUMBER     "Unit"
#define     CONFIGFILE_ACTIVE_TARGET_CIRCUIT        "Circuit"
