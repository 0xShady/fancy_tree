printf("%c\n", 14)
printf("%c ", 0x6A) # ┘

printf("%c ", 0x6B) # ┐

printf("%c ", 0x6C) # ┌

printf("%c ", 0x6D) # └

printf("%c ", 0x6E) # ┼

printf("%c ", 0x71) # ─

printf("%c ", 0x74) # ├

printf("%c ", 0x75) # ┤

printf("%c ", 0x76) # ┴

printf("%c ", 0x77) # ┬

printf("%c\n", 0x78) # │


a = sprintf("%c", 0x6C) + # ┌
sprintf("%c", 0x71) + # ─
sprintf("%c", 0x71) + # ─
sprintf("%c", 0x71) + # ─
sprintf("%c", 0x71) + # ─
sprintf("%c", 0x71) + # ─
sprintf("%c", 0x71) + # ─
sprintf("%c\n", 0x6B) +  # ┐
sprintf("%c", 0x78) + # │
#print("      ")
"      " + 
sprintf("%c\n", 0x78) + # │
sprintf("%c", 0x6D) + # └
sprintf("%c", 0x71) + # ─
sprintf("%c", 0x71) + # ─
sprintf("%c", 0x71) + # ─
sprintf("%c", 0x71) + # ─
sprintf("%c", 0x71) + # ─
sprintf("%c", 0x71) + # ─
sprintf("%c", 0x6A)  # ┘