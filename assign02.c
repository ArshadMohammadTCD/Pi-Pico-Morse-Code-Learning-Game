// Must declare the main assembly entry point before use.
void main_asm();

/*
 * Main entry point for the code - simply calls the main assembly function.
 */
int main() {
    main_asm();
    return(0);
}