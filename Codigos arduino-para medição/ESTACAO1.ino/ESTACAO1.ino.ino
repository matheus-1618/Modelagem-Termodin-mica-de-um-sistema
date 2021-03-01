void setup() {
  // Comunicação Serial 9600 bps
  Serial.begin(9600);
  
  // Referência AD Interna. Fundo de escala de 1,1 volt 
  // (equivalente a 110 graus Celsius no LM35)
  analogReference(INTERNAL);
}
int t=0;
void loop() {
  // Lê tensão Analógica na porta A0
  // O valor lido será um inteiro entre 0 e 1023
  int leitura_adc = analogRead(A0);
  // Converte o valor lido para um valor em volts
  // 1.1 ou 1.1f para forçar numero real
  float voltagem = leitura_adc * (1.1f/1023);
  // Calcula a temperatura
  // LM35: 10mV => 1 grau C
  float temperatura = voltagem * 100.0;
  Serial.println(temperatura, 3);
  // Aguarda 15 segundos
  delay(15000);
  
}
