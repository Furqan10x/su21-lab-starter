.globl factorial

.data
n: .word 11

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, t0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
       # Function prologue
    addi sp, sp, -4      # Allocate space on the stack
    sw ra, 0(sp)         # Save return address on the stack

    # Function body
    li t0, 1            # Initialize t0 (result) to 1
    li t1, 1          # Initialize t1 (counter) to 1

loop:
    blt a0, t1, end_loop  # Exit loop if t1 >= a0
    mul t0, t0, t1       # Multiply result by counter
    addi t1, t1, 1       # Increment counter
    j loop               # Jump back to loop

end_loop:
    # Function epilogue
    lw ra, 0(sp)         # Restore return address from the stack
    addi sp, sp, 4       # Deallocate space on the stack
    jr ra                # Jump back to the return address
