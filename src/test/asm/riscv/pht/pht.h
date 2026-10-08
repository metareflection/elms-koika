/* The globals every Kocher variant shares, scaled to a 64-word `mem`.
 *
 * `spectector-benchmarks/sources/compiler-countermeasures` declares
 *
 *   unsigned int array1_size = 16;
 *   uint8_t array1[16] = { 1,2,...,16 };
 *   uint8_t array2[256 * 512];
 *   uint8_t temp = 0;
 *
 * and nothing secret, because the leak there is reading past `array1` into
 * whatever the linker put next. Here `.secret` is what the thing next door is,
 * so the variants become demos without any of them changing shape.
 *
 * Words rather than bytes, because `mem` is `int[]` and the driver writes it a
 * word at a time, so a `uint8_t` array would put four secret bytes in one draw
 * and hand three of them a constant zero.
 *
 * `probe` is `array2` with one line per value instead of one page: the
 * geometry's line is two words, so `(v & 7) * 2` lands eight values on eight
 * distinct lines. `publicarray_size` stays a variable and does not become an
 * `#define`, because every original loads it, and a bound check that waits on
 * a load is the part a predictor gets to run ahead of.
 *
 * The declaration order is load bearing and so are the `= {0}`s. clang emits an
 * uninitialized global where it is first referenced, which would leave `probe`
 * and `temp` sitting between the attacker's array and the key; an initializer
 * makes it emit in declaration order instead. `secretarray` is the one left
 * tentative, so it is emitted last and lands exactly where `publicarray` ends.
 * `RiscVElfTests` checks that back out of the object.
 */
#include <stdint.h>

uint32_t publicarray_size = 8;

__attribute__((section(".attacker"))) uint32_t probe[16] = {0};
__attribute__((section(".attacker"))) uint32_t temp = 0;
__attribute__((section(".attacker"))) uint32_t publicarray[8] = {0};

__attribute__((section(".secret"))) uint32_t secretarray[8];
