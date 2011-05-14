#include "key.h"
#include <SDL/SDL.h>

void game_engine_key_init( FeriteScript *script, FeriteNamespace *engine_namespace )
{
	ferite_register_ns_variable(script, engine_namespace, "KEY_BACKSPACE", ferite_create_number_long_variable(script, "KEY_BACKSPACE", SDLK_BACKSPACE, FE_STATIC)); /* '\b' backspace */
	ferite_register_ns_variable(script, engine_namespace, "KEY_TAB", ferite_create_number_long_variable(script, "KEY_TAB", SDLK_TAB, FE_STATIC)); /* '\t' tab */
	ferite_register_ns_variable(script, engine_namespace, "KEY_CLEAR", ferite_create_number_long_variable(script, "KEY_CLEAR", SDLK_CLEAR, FE_STATIC)); /*  clear */
	ferite_register_ns_variable(script, engine_namespace, "KEY_RETURN", ferite_create_number_long_variable(script, "KEY_RETURN", SDLK_RETURN, FE_STATIC)); /* '\r' return */
	ferite_register_ns_variable(script, engine_namespace, "KEY_PAUSE", ferite_create_number_long_variable(script, "KEY_PAUSE", SDLK_PAUSE, FE_STATIC)); /*  pause */
	ferite_register_ns_variable(script, engine_namespace, "KEY_ESCAPE", ferite_create_number_long_variable(script, "KEY_ESCAPE", SDLK_ESCAPE, FE_STATIC)); /* '^[' escape */
	ferite_register_ns_variable(script, engine_namespace, "KEY_SPACE", ferite_create_number_long_variable(script, "KEY_SPACE", SDLK_SPACE, FE_STATIC)); /* ' ' space */
	ferite_register_ns_variable(script, engine_namespace, "KEY_EXCLAIM", ferite_create_number_long_variable(script, "KEY_EXCLAIM", SDLK_EXCLAIM, FE_STATIC)); /* '!' exclaim */
	ferite_register_ns_variable(script, engine_namespace, "KEY_QUOTEDBL", ferite_create_number_long_variable(script, "KEY_QUOTEDBL", SDLK_QUOTEDBL, FE_STATIC)); /* '"' quotedbl */
	ferite_register_ns_variable(script, engine_namespace, "KEY_HASH", ferite_create_number_long_variable(script, "KEY_HASH", SDLK_HASH, FE_STATIC)); /* '#' hash */
	ferite_register_ns_variable(script, engine_namespace, "KEY_DOLLAR", ferite_create_number_long_variable(script, "KEY_DOLLAR", SDLK_DOLLAR, FE_STATIC)); /* '$' dollar */
	ferite_register_ns_variable(script, engine_namespace, "KEY_AMPERSAND", ferite_create_number_long_variable(script, "KEY_AMPERSAND", SDLK_AMPERSAND, FE_STATIC)); /* '&amp;' ampersand */
	ferite_register_ns_variable(script, engine_namespace, "KEY_QUOTE", ferite_create_number_long_variable(script, "KEY_QUOTE", SDLK_QUOTE, FE_STATIC)); /* ''' quote */
	ferite_register_ns_variable(script, engine_namespace, "KEY_LEFTPAREN", ferite_create_number_long_variable(script, "KEY_LEFTPAREN", SDLK_LEFTPAREN, FE_STATIC)); /* '(' left parenthesis */
	ferite_register_ns_variable(script, engine_namespace, "KEY_RIGHTPAREN", ferite_create_number_long_variable(script, "KEY_RIGHTPAREN", SDLK_RIGHTPAREN, FE_STATIC)); /* ')' right parenthesis */
	ferite_register_ns_variable(script, engine_namespace, "KEY_ASTERISK", ferite_create_number_long_variable(script, "KEY_ASTERISK", SDLK_ASTERISK, FE_STATIC)); /* '*' asterisk */
	ferite_register_ns_variable(script, engine_namespace, "KEY_PLUS", ferite_create_number_long_variable(script, "KEY_PLUS", SDLK_PLUS, FE_STATIC)); /* '+' plus sign */
	ferite_register_ns_variable(script, engine_namespace, "KEY_COMMA", ferite_create_number_long_variable(script, "KEY_COMMA", SDLK_COMMA, FE_STATIC)); /* ',' comma */
	ferite_register_ns_variable(script, engine_namespace, "KEY_MINUS", ferite_create_number_long_variable(script, "KEY_MINUS", SDLK_MINUS, FE_STATIC)); /* '-' minus sign */
	ferite_register_ns_variable(script, engine_namespace, "KEY_PERIOD", ferite_create_number_long_variable(script, "KEY_PERIOD", SDLK_PERIOD, FE_STATIC)); /* '.' period */
	ferite_register_ns_variable(script, engine_namespace, "KEY_SLASH", ferite_create_number_long_variable(script, "KEY_SLASH", SDLK_SLASH, FE_STATIC)); /* '/' forward slash */
	ferite_register_ns_variable(script, engine_namespace, "KEY_0", ferite_create_number_long_variable(script, "KEY_0", SDLK_0, FE_STATIC)); /* '0' 0 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_1", ferite_create_number_long_variable(script, "KEY_1", SDLK_1, FE_STATIC)); /* '1' 1 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_2", ferite_create_number_long_variable(script, "KEY_2", SDLK_2, FE_STATIC)); /* '2' 2 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_3", ferite_create_number_long_variable(script, "KEY_3", SDLK_3, FE_STATIC)); /* '3' 3 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_4", ferite_create_number_long_variable(script, "KEY_4", SDLK_4, FE_STATIC)); /* '4' 4 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_5", ferite_create_number_long_variable(script, "KEY_5", SDLK_5, FE_STATIC)); /* '5' 5 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_6", ferite_create_number_long_variable(script, "KEY_6", SDLK_6, FE_STATIC)); /* '6' 6 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_7", ferite_create_number_long_variable(script, "KEY_7", SDLK_7, FE_STATIC)); /* '7' 7 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_8", ferite_create_number_long_variable(script, "KEY_8", SDLK_8, FE_STATIC)); /* '8' 8 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_9", ferite_create_number_long_variable(script, "KEY_9", SDLK_9, FE_STATIC)); /* '9' 9 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_COLON", ferite_create_number_long_variable(script, "KEY_COLON", SDLK_COLON, FE_STATIC)); /* ':' colon */
	ferite_register_ns_variable(script, engine_namespace, "KEY_SEMICOLON", ferite_create_number_long_variable(script, "KEY_SEMICOLON", SDLK_SEMICOLON, FE_STATIC)); /* ';' semicolon */
	ferite_register_ns_variable(script, engine_namespace, "KEY_LESS", ferite_create_number_long_variable(script, "KEY_LESS", SDLK_LESS, FE_STATIC)); /* '&lt;' less-than sign */
	ferite_register_ns_variable(script, engine_namespace, "KEY_EQUALS", ferite_create_number_long_variable(script, "KEY_EQUALS", SDLK_EQUALS, FE_STATIC)); /* '=' equals sign */
	ferite_register_ns_variable(script, engine_namespace, "KEY_GREATER", ferite_create_number_long_variable(script, "KEY_GREATER", SDLK_GREATER, FE_STATIC)); /* '&gt;' greater-than sign */
	ferite_register_ns_variable(script, engine_namespace, "KEY_QUESTION", ferite_create_number_long_variable(script, "KEY_QUESTION", SDLK_QUESTION, FE_STATIC)); /* '?' question mark */
	ferite_register_ns_variable(script, engine_namespace, "KEY_AT", ferite_create_number_long_variable(script, "KEY_AT", SDLK_AT, FE_STATIC)); /* '@' at */
	ferite_register_ns_variable(script, engine_namespace, "KEY_LEFTBRACKET", ferite_create_number_long_variable(script, "KEY_LEFTBRACKET", SDLK_LEFTBRACKET, FE_STATIC)); /* '[' left bracket */
	ferite_register_ns_variable(script, engine_namespace, "KEY_BACKSLASH", ferite_create_number_long_variable(script, "KEY_BACKSLASH", SDLK_BACKSLASH, FE_STATIC)); /* '\' backslash */
	ferite_register_ns_variable(script, engine_namespace, "KEY_RIGHTBRACKET", ferite_create_number_long_variable(script, "KEY_RIGHTBRACKET", SDLK_RIGHTBRACKET, FE_STATIC)); /* ']' right bracket */
	ferite_register_ns_variable(script, engine_namespace, "KEY_CARET", ferite_create_number_long_variable(script, "KEY_CARET", SDLK_CARET, FE_STATIC)); /* '^' caret */
	ferite_register_ns_variable(script, engine_namespace, "KEY_UNDERSCORE", ferite_create_number_long_variable(script, "KEY_UNDERSCORE", SDLK_UNDERSCORE, FE_STATIC)); /* '_' underscore */
	ferite_register_ns_variable(script, engine_namespace, "KEY_BACKQUOTE", ferite_create_number_long_variable(script, "KEY_BACKQUOTE", SDLK_BACKQUOTE, FE_STATIC)); /* '`' grave */
	ferite_register_ns_variable(script, engine_namespace, "KEY_a", ferite_create_number_long_variable(script, "KEY_a", SDLK_a, FE_STATIC)); /* 'a' a */
	ferite_register_ns_variable(script, engine_namespace, "KEY_b", ferite_create_number_long_variable(script, "KEY_b", SDLK_b, FE_STATIC)); /* 'b' b */
	ferite_register_ns_variable(script, engine_namespace, "KEY_c", ferite_create_number_long_variable(script, "KEY_c", SDLK_c, FE_STATIC)); /* 'c' c */
	ferite_register_ns_variable(script, engine_namespace, "KEY_d", ferite_create_number_long_variable(script, "KEY_d", SDLK_d, FE_STATIC)); /* 'd' d */
	ferite_register_ns_variable(script, engine_namespace, "KEY_e", ferite_create_number_long_variable(script, "KEY_e", SDLK_e, FE_STATIC)); /* 'e' e */
	ferite_register_ns_variable(script, engine_namespace, "KEY_f", ferite_create_number_long_variable(script, "KEY_f", SDLK_f, FE_STATIC)); /* 'f' f */
	ferite_register_ns_variable(script, engine_namespace, "KEY_g", ferite_create_number_long_variable(script, "KEY_g", SDLK_g, FE_STATIC)); /* 'g' g */
	ferite_register_ns_variable(script, engine_namespace, "KEY_h", ferite_create_number_long_variable(script, "KEY_h", SDLK_h, FE_STATIC)); /* 'h' h */
	ferite_register_ns_variable(script, engine_namespace, "KEY_i", ferite_create_number_long_variable(script, "KEY_i", SDLK_i, FE_STATIC)); /* 'i' i */
	ferite_register_ns_variable(script, engine_namespace, "KEY_j", ferite_create_number_long_variable(script, "KEY_j", SDLK_j, FE_STATIC)); /* 'j' j */
	ferite_register_ns_variable(script, engine_namespace, "KEY_k", ferite_create_number_long_variable(script, "KEY_k", SDLK_k, FE_STATIC)); /* 'k' k */
	ferite_register_ns_variable(script, engine_namespace, "KEY_l", ferite_create_number_long_variable(script, "KEY_l", SDLK_l, FE_STATIC)); /* 'l' l */
	ferite_register_ns_variable(script, engine_namespace, "KEY_m", ferite_create_number_long_variable(script, "KEY_m", SDLK_m, FE_STATIC)); /* 'm' m */
	ferite_register_ns_variable(script, engine_namespace, "KEY_n", ferite_create_number_long_variable(script, "KEY_n", SDLK_n, FE_STATIC)); /* 'n' n */
	ferite_register_ns_variable(script, engine_namespace, "KEY_o", ferite_create_number_long_variable(script, "KEY_o", SDLK_o, FE_STATIC)); /* 'o' o */
	ferite_register_ns_variable(script, engine_namespace, "KEY_p", ferite_create_number_long_variable(script, "KEY_p", SDLK_p, FE_STATIC)); /* 'p' p */
	ferite_register_ns_variable(script, engine_namespace, "KEY_q", ferite_create_number_long_variable(script, "KEY_q", SDLK_q, FE_STATIC)); /* 'q' q */
	ferite_register_ns_variable(script, engine_namespace, "KEY_r", ferite_create_number_long_variable(script, "KEY_r", SDLK_r, FE_STATIC)); /* 'r' r */
	ferite_register_ns_variable(script, engine_namespace, "KEY_s", ferite_create_number_long_variable(script, "KEY_s", SDLK_s, FE_STATIC)); /* 's' s */
	ferite_register_ns_variable(script, engine_namespace, "KEY_t", ferite_create_number_long_variable(script, "KEY_t", SDLK_t, FE_STATIC)); /* 't' t */
	ferite_register_ns_variable(script, engine_namespace, "KEY_u", ferite_create_number_long_variable(script, "KEY_u", SDLK_u, FE_STATIC)); /* 'u' u */
	ferite_register_ns_variable(script, engine_namespace, "KEY_v", ferite_create_number_long_variable(script, "KEY_v", SDLK_v, FE_STATIC)); /* 'v' v */
	ferite_register_ns_variable(script, engine_namespace, "KEY_w", ferite_create_number_long_variable(script, "KEY_w", SDLK_w, FE_STATIC)); /* 'w' w */
	ferite_register_ns_variable(script, engine_namespace, "KEY_x", ferite_create_number_long_variable(script, "KEY_x", SDLK_x, FE_STATIC)); /* 'x' x */
	ferite_register_ns_variable(script, engine_namespace, "KEY_y", ferite_create_number_long_variable(script, "KEY_y", SDLK_y, FE_STATIC)); /* 'y' y */
	ferite_register_ns_variable(script, engine_namespace, "KEY_z", ferite_create_number_long_variable(script, "KEY_z", SDLK_z, FE_STATIC)); /* 'z' z */
	ferite_register_ns_variable(script, engine_namespace, "KEY_DELETE", ferite_create_number_long_variable(script, "KEY_DELETE", SDLK_DELETE, FE_STATIC)); /* '^?' delete */
	ferite_register_ns_variable(script, engine_namespace, "KEY_KP0", ferite_create_number_long_variable(script, "KEY_KP0", SDLK_KP0, FE_STATIC)); /*  keypad 0 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_KP1", ferite_create_number_long_variable(script, "KEY_KP1", SDLK_KP1, FE_STATIC)); /*  keypad 1 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_KP2", ferite_create_number_long_variable(script, "KEY_KP2", SDLK_KP2, FE_STATIC)); /*  keypad 2 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_KP3", ferite_create_number_long_variable(script, "KEY_KP3", SDLK_KP3, FE_STATIC)); /*  keypad 3 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_KP4", ferite_create_number_long_variable(script, "KEY_KP4", SDLK_KP4, FE_STATIC)); /*  keypad 4 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_KP5", ferite_create_number_long_variable(script, "KEY_KP5", SDLK_KP5, FE_STATIC)); /*  keypad 5 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_KP6", ferite_create_number_long_variable(script, "KEY_KP6", SDLK_KP6, FE_STATIC)); /*  keypad 6 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_KP7", ferite_create_number_long_variable(script, "KEY_KP7", SDLK_KP7, FE_STATIC)); /*  keypad 7 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_KP8", ferite_create_number_long_variable(script, "KEY_KP8", SDLK_KP8, FE_STATIC)); /*  keypad 8 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_KP9", ferite_create_number_long_variable(script, "KEY_KP9", SDLK_KP9, FE_STATIC)); /*  keypad 9 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_KP_PERIOD", ferite_create_number_long_variable(script, "KEY_KP_PERIOD", SDLK_KP_PERIOD, FE_STATIC)); /* '.' keypad period */
	ferite_register_ns_variable(script, engine_namespace, "KEY_KP_DIVIDE", ferite_create_number_long_variable(script, "KEY_KP_DIVIDE", SDLK_KP_DIVIDE, FE_STATIC)); /* '/' keypad divide */
	ferite_register_ns_variable(script, engine_namespace, "KEY_KP_MULTIPLY", ferite_create_number_long_variable(script, "KEY_KP_MULTIPLY", SDLK_KP_MULTIPLY, FE_STATIC)); /* '*' keypad multiply */
	ferite_register_ns_variable(script, engine_namespace, "KEY_KP_MINUS", ferite_create_number_long_variable(script, "KEY_KP_MINUS", SDLK_KP_MINUS, FE_STATIC)); /* '-' keypad minus */
	ferite_register_ns_variable(script, engine_namespace, "KEY_KP_PLUS", ferite_create_number_long_variable(script, "KEY_KP_PLUS", SDLK_KP_PLUS, FE_STATIC)); /* '+' keypad plus */
	ferite_register_ns_variable(script, engine_namespace, "KEY_KP_ENTER", ferite_create_number_long_variable(script, "KEY_KP_ENTER", SDLK_KP_ENTER, FE_STATIC)); /* '\r' keypad enter */
	ferite_register_ns_variable(script, engine_namespace, "KEY_KP_EQUALS", ferite_create_number_long_variable(script, "KEY_KP_EQUALS", SDLK_KP_EQUALS, FE_STATIC)); /* '=' keypad equals */
	ferite_register_ns_variable(script, engine_namespace, "KEY_UP", ferite_create_number_long_variable(script, "KEY_UP", SDLK_UP, FE_STATIC)); /*  up arrow */
	ferite_register_ns_variable(script, engine_namespace, "KEY_DOWN", ferite_create_number_long_variable(script, "KEY_DOWN", SDLK_DOWN, FE_STATIC)); /*  down arrow */
	ferite_register_ns_variable(script, engine_namespace, "KEY_RIGHT", ferite_create_number_long_variable(script, "KEY_RIGHT", SDLK_RIGHT, FE_STATIC)); /*  right arrow */
	ferite_register_ns_variable(script, engine_namespace, "KEY_LEFT", ferite_create_number_long_variable(script, "KEY_LEFT", SDLK_LEFT, FE_STATIC)); /*  left arrow */
	ferite_register_ns_variable(script, engine_namespace, "KEY_INSERT", ferite_create_number_long_variable(script, "KEY_INSERT", SDLK_INSERT, FE_STATIC)); /*  insert */
	ferite_register_ns_variable(script, engine_namespace, "KEY_HOME", ferite_create_number_long_variable(script, "KEY_HOME", SDLK_HOME, FE_STATIC)); /*  home */
	ferite_register_ns_variable(script, engine_namespace, "KEY_END", ferite_create_number_long_variable(script, "KEY_END", SDLK_END, FE_STATIC)); /*  end */
	ferite_register_ns_variable(script, engine_namespace, "KEY_PAGEUP", ferite_create_number_long_variable(script, "KEY_PAGEUP", SDLK_PAGEUP, FE_STATIC)); /*  page up */
	ferite_register_ns_variable(script, engine_namespace, "KEY_PAGEDOWN", ferite_create_number_long_variable(script, "KEY_PAGEDOWN", SDLK_PAGEDOWN, FE_STATIC)); /*  page down */
	ferite_register_ns_variable(script, engine_namespace, "KEY_F1", ferite_create_number_long_variable(script, "KEY_F1", SDLK_F1, FE_STATIC)); /*  F1 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_F2", ferite_create_number_long_variable(script, "KEY_F2", SDLK_F2, FE_STATIC)); /*  F2 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_F3", ferite_create_number_long_variable(script, "KEY_F3", SDLK_F3, FE_STATIC)); /*  F3 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_F4", ferite_create_number_long_variable(script, "KEY_F4", SDLK_F4, FE_STATIC)); /*  F4 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_F5", ferite_create_number_long_variable(script, "KEY_F5", SDLK_F5, FE_STATIC)); /*  F5 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_F6", ferite_create_number_long_variable(script, "KEY_F6", SDLK_F6, FE_STATIC)); /*  F6 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_F7", ferite_create_number_long_variable(script, "KEY_F7", SDLK_F7, FE_STATIC)); /*  F7 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_F8", ferite_create_number_long_variable(script, "KEY_F8", SDLK_F8, FE_STATIC)); /*  F8 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_F9", ferite_create_number_long_variable(script, "KEY_F9", SDLK_F9, FE_STATIC)); /*  F9 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_F10", ferite_create_number_long_variable(script, "KEY_F10", SDLK_F10, FE_STATIC)); /*  F10 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_F11", ferite_create_number_long_variable(script, "KEY_F11", SDLK_F11, FE_STATIC)); /*  F11 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_F12", ferite_create_number_long_variable(script, "KEY_F12", SDLK_F12, FE_STATIC)); /*  F12 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_F13", ferite_create_number_long_variable(script, "KEY_F13", SDLK_F13, FE_STATIC)); /*  F13 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_F14", ferite_create_number_long_variable(script, "KEY_F14", SDLK_F14, FE_STATIC)); /*  F14 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_F15", ferite_create_number_long_variable(script, "KEY_F15", SDLK_F15, FE_STATIC)); /*  F15 */
	ferite_register_ns_variable(script, engine_namespace, "KEY_NUMLOCK", ferite_create_number_long_variable(script, "KEY_NUMLOCK", SDLK_NUMLOCK, FE_STATIC)); /*  numlock */
	ferite_register_ns_variable(script, engine_namespace, "KEY_CAPSLOCK", ferite_create_number_long_variable(script, "KEY_CAPSLOCK", SDLK_CAPSLOCK, FE_STATIC)); /*  capslock */
	ferite_register_ns_variable(script, engine_namespace, "KEY_SCROLLOCK", ferite_create_number_long_variable(script, "KEY_SCROLLOCK", SDLK_SCROLLOCK, FE_STATIC)); /*  scrollock */
	ferite_register_ns_variable(script, engine_namespace, "KEY_RSHIFT", ferite_create_number_long_variable(script, "KEY_RSHIFT", SDLK_RSHIFT, FE_STATIC)); /*  right shift */
	ferite_register_ns_variable(script, engine_namespace, "KEY_LSHIFT", ferite_create_number_long_variable(script, "KEY_LSHIFT", SDLK_LSHIFT, FE_STATIC)); /*  left shift */
	ferite_register_ns_variable(script, engine_namespace, "KEY_RCTRL", ferite_create_number_long_variable(script, "KEY_RCTRL", SDLK_RCTRL, FE_STATIC)); /*  right ctrl */
	ferite_register_ns_variable(script, engine_namespace, "KEY_LCTRL", ferite_create_number_long_variable(script, "KEY_LCTRL", SDLK_LCTRL, FE_STATIC)); /*  left ctrl */
	ferite_register_ns_variable(script, engine_namespace, "KEY_RALT", ferite_create_number_long_variable(script, "KEY_RALT", SDLK_RALT, FE_STATIC)); /*  right alt */
	ferite_register_ns_variable(script, engine_namespace, "KEY_LALT", ferite_create_number_long_variable(script, "KEY_LALT", SDLK_LALT, FE_STATIC)); /*  left alt */
	ferite_register_ns_variable(script, engine_namespace, "KEY_RMETA", ferite_create_number_long_variable(script, "KEY_RMETA", SDLK_RMETA, FE_STATIC)); /*  right meta */
	ferite_register_ns_variable(script, engine_namespace, "KEY_LMETA", ferite_create_number_long_variable(script, "KEY_LMETA", SDLK_LMETA, FE_STATIC)); /*  left meta */
	ferite_register_ns_variable(script, engine_namespace, "KEY_LSUPER", ferite_create_number_long_variable(script, "KEY_LSUPER", SDLK_LSUPER, FE_STATIC)); /*  left windows key */
	ferite_register_ns_variable(script, engine_namespace, "KEY_RSUPER", ferite_create_number_long_variable(script, "KEY_RSUPER", SDLK_RSUPER, FE_STATIC)); /*  right windows key */
	ferite_register_ns_variable(script, engine_namespace, "KEY_MODE", ferite_create_number_long_variable(script, "KEY_MODE", SDLK_MODE, FE_STATIC)); /*  mode shift */
	ferite_register_ns_variable(script, engine_namespace, "KEY_HELP", ferite_create_number_long_variable(script, "KEY_HELP", SDLK_HELP, FE_STATIC)); /*  help */
	ferite_register_ns_variable(script, engine_namespace, "KEY_PRINT", ferite_create_number_long_variable(script, "KEY_PRINT", SDLK_PRINT, FE_STATIC)); /*  print-screen */
	ferite_register_ns_variable(script, engine_namespace, "KEY_SYSREQ", ferite_create_number_long_variable(script, "KEY_SYSREQ", SDLK_SYSREQ, FE_STATIC)); /*  SysRq */
	ferite_register_ns_variable(script, engine_namespace, "KEY_BREAK", ferite_create_number_long_variable(script, "KEY_BREAK", SDLK_BREAK, FE_STATIC)); /*  break */
	ferite_register_ns_variable(script, engine_namespace, "KEY_MENU", ferite_create_number_long_variable(script, "KEY_MENU", SDLK_MENU, FE_STATIC)); /*  menu */
	ferite_register_ns_variable(script, engine_namespace, "KEY_POWER", ferite_create_number_long_variable(script, "KEY_POWER", SDLK_POWER, FE_STATIC)); /*  power */
	ferite_register_ns_variable(script, engine_namespace, "KEY_EURO", ferite_create_number_long_variable(script, "KEY_EURO", SDLK_EURO, FE_STATIC)); /*  euro */
}

