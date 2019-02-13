#ifndef GAME_H
#define GAME_H

#include <gbdkjs.h>
#include <gb/gb.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "BankManager.h"
#include "banks.h"
#include "script_cmds.h"
#include "data_ptrs.h"

#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 144
#define SCREEN_WIDTH_HALF 80
#define SCREEN_HEIGHT_HALF 72

// Start of Types - @todo move these to Types.h

typedef enum
{
  TITLE = 1,
  LOGO,
  MAP
} STAGE_TYPE;

typedef enum
{
  NONE = 1,
  PLAYER_INPUT,
  AI_RANDOM_FACE,
  AI_INTERACT_FACE,
  AI_RANDOM_WALK,
} MOVEMENT_TYPE;

typedef struct _POS
{
  UBYTE x;
  UBYTE y;
} POS;

typedef struct _SIZE
{
  UBYTE w;
  UBYTE h;
} SIZE;

typedef struct _VEC2D
{
  BYTE x;
  BYTE y;
} VEC2D;

typedef struct _ACTORSPRITE
{
  UBYTE sprite;
  POS pos;
  VEC2D dir;
  UBYTE redraw;
  UBYTE enabled;
  UBYTE moving;
  UBYTE animated;
  UWORD script_ptr;
  BANK_PTR events_ptr;
  MOVEMENT_TYPE movement_type;
} ACTOR;

typedef struct _TRIGGER
{
  POS pos;
  UBYTE w;
  UBYTE h;
  UWORD script_ptr;
  BANK_PTR events_ptr;
} TRIGGER;

typedef void (*SCRIPT_CMD_FN)();

// End of Types

// Functions
void set_text_line(UWORD line);
void draw_text(UBYTE force);

// Extern - @todo move most of these out of game.h
extern SCRIPT_CMD_FN last_fn;
extern UWORD script_ptr;
extern UBYTE script_action_complete;
extern UBYTE script_continue;
extern UBYTE script_arg1;
extern UBYTE script_arg2;
extern UBYTE script_arg3;
extern UBYTE script_arg4;
extern UBYTE script_arg5;
extern UBYTE script_actor;
extern UBYTE wait_time;
extern UBYTE shake_time;
extern POS camera_dest;
extern UBYTE camera_settings;
extern STAGE_TYPE stage_type;
extern STAGE_TYPE stage_next_type;
extern UBYTE actor_move_settings;
extern POS actor_move_dest;
extern UBYTE joy;
extern UBYTE prev_joy;
extern UBYTE time;
extern UBYTE menu_y;
extern UBYTE menu_dest_y;
extern UBYTE text_drawn;
extern const unsigned char village_sprites[];
extern const unsigned char emotion_sprites[];

#endif
