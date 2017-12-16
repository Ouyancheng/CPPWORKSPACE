#include <cstdio>
/* %rdi %rsi %rdx %rcx %r8 %r9 */
long test_inline_asm(long a, long b) {
	asm(
		"movq %rdi, %rax \n\t"
		"addq %rsi, %rax \n\t"
		"popq %rbp \n\t"
		"ret \n\t"
	);
	return 0;
}

int main() {
	// asm(
	// 	"movq $1, %rdi \n\t"
	// 	"movq $2, %rsi \n\t"
	// 	"callq _test_inline_asm \n\t"
	// 	"popq %rbp \n\t"
	// 	"ret \n\t"
	// );
	printf("%ld\n", test_inline_asm(1, 2));
	return 0;
}

