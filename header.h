extern void UART0_init(unsigned int baud);
extern void UART0_tx(unsigned char data);
extern void UART0_tx_string(char *ptr);
extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init(void);
extern void delay_ms(unsigned int ms);
extern void delay_sec(unsigned int sec);
