#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

// #define TAPPING_TOGGLE 2  /* Tapping this number of tiles to enable or disable a layer with TT */
#undef  TAPPING_TERM
#define TAPPING_TERM 175  /* Maximum time between two taps */

#define LEADER_TIMEOUT 250  /* Timeout after leader key is pressed */
#define LEADER_PER_KEY_TIMING  /* The timeout is reset each times a key is pressed */

#endif
