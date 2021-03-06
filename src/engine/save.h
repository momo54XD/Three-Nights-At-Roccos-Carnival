// (c) 2020 MotoLegacy
// This code is licensed under MIT license (see LICENSE for details)

//FNAF 1
#ifdef GAME_FNAF1
  #define SAVE_TITLE   "freddy"
#endif

//FNAF 2
#ifdef GAME_FNAF2
  #define SAVE_TITLE   "freddy2"
#endif

//FNAF 3
#ifdef GAME_FNAF3
  #define SAVE_TITLE   "freddy3"
#endif

extern void Save_Create(void);
extern bool Save_Exist();
extern u16_t Save_GetValue(char* target);
extern void Save_SetValue(char* target, u16_t value);