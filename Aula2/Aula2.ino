#define LED_ESQUERDA 2
#define LED_CENTRO 3
#define LED_DIREITA 4
int count;
int maxi;

enum estados_fsm {ACENDE_LED_ESQUERDA, APAGA_LED_ESQUERDA,
                  ACENDE_LED_CENTRO_1, APAGA_LED_CENTRO_1,  
                ACENDE_LED_CENTRO_2, APAGA_LED_CENTRO_2,
              ACENDE_LED_DIREITA, APAGA_LED_DIREITA} estado_atual;

// funcao de configuracao do sistema na inicializacao
void setup() {
  // initializa os pinos de saida
  
  //Serial.begin(9600);
  
  count = 0;
  maxi = 10000;

  pinMode(LED_ESQUERDA, OUTPUT);
  pinMode(LED_CENTRO, OUTPUT);
  pinMode(LED_DIREITA, OUTPUT);
  estado_atual = ACENDE_LED_ESQUERDA;
}

// loop infinito
void loop() { 
  if (count == maxi) {
    count = 0; 
  } 
  Serial.println(count);
  if (count == 0) {
    switch(estado_atual) {
        case ACENDE_LED_ESQUERDA:
          digitalWrite(LED_ESQUERDA, HIGH);
          estado_atual = APAGA_LED_ESQUERDA;
          break;
          
        case APAGA_LED_ESQUERDA:
          digitalWrite(LED_ESQUERDA, LOW);
          estado_atual = ACENDE_LED_CENTRO_1;
          break;
    
        case ACENDE_LED_CENTRO_1:
          digitalWrite(LED_CENTRO, HIGH);
          estado_atual = APAGA_LED_CENTRO_1;
          break;
          
        case APAGA_LED_CENTRO_1:
          digitalWrite(LED_CENTRO, LOW);
          estado_atual = ACENDE_LED_DIREITA;
          break;
    
        case ACENDE_LED_DIREITA:
          digitalWrite(LED_DIREITA, HIGH);
          estado_atual = APAGA_LED_DIREITA;
          break;
            
        case APAGA_LED_DIREITA:
          digitalWrite(LED_DIREITA, LOW);
          estado_atual = ACENDE_LED_CENTRO_2;
          break;
    
        case ACENDE_LED_CENTRO_2:
          digitalWrite(LED_CENTRO, HIGH);
          estado_atual = APAGA_LED_CENTRO_2;
          break;
          
        case APAGA_LED_CENTRO_2:
          digitalWrite(LED_CENTRO, LOW);
          estado_atual = ACENDE_LED_ESQUERDA;
          break;
        
        default:
          estado_atual = ACENDE_LED_ESQUERDA;
          break;
    }
  }
 count+=1; 
}
