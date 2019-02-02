int r = 7;
int g = 6;
int v = 5;
int r1 = 4;
int g1 = 3;
int v1 = 2;
int drosso = 3000;
int dverde = 500;
int dgiallo = 800;
String lampeggi;
String incomingByte;
bool check = true;
void setup() {
  pinMode(r, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(v, OUTPUT);
  pinMode(v1, OUTPUT);
  Serial.begin(9600);
  Serial.print("Impostazioni semaforo \n");
}

void loop() {
  if(check == true){
    Serial.print("Seleziona quanti lampeggi");
  }
  check = false;
  if(Serial.available() > 0){
    lampeggi = Serial.readString();
    Serial.print("\nHai selezionato: ");
    Serial.print(lampeggi.toInt());
    Serial.print("\n");
  }
  if(lampeggi != NULL){
      esecuzione(r, v1);
      esecuzione(r1, v);
  }
}

void lampeggio(int v){
  for(int i = 0; i < lampeggi.toInt(); i++){
    digitalWrite(v, HIGH);
    delay(dverde);
    digitalWrite(v,LOW);
    delay(dverde); 
  }
}

void gestgiallo(){
  digitalWrite(g, HIGH);
  digitalWrite(g1, HIGH);
  delay(dgiallo);  
  digitalWrite(g, LOW);
  digitalWrite(g1, LOW);
}

void esecuzione(int rosso, int verde){
  digitalWrite(rosso, HIGH);
  digitalWrite(verde, HIGH);
  delay(drosso);
  lampeggio(verde);
  gestgiallo();
  digitalWrite(rosso,LOW);
}
