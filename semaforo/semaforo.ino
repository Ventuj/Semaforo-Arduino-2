int r = 7;
int g = 6;
int v = 5;
int r1 = 4;
int g1 = 3;
int v1 = 2;
int drosso;
int dverde = 500;
int dgiallo = 800;
int lampeggi;
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
  if(check){
    Serial.print("Seleziona quanti lampeggi");
  }
  check = false;
  while(Serial.available() == 0){}
  lampeggi = serialInput(Serial.readString());
  Serial.print("\nHai selezionato: ");
  Serial.print(lampeggi);
  Serial.print("\nSeleziona Durata rosso in MilliSecondi");
  while(Serial.available() == 0){}
  drosso = serialInput(Serial.readString());
  Serial.print("\nHai selezionato: ");
  Serial.print(drosso);
  if(lampeggi != NULL && drosso != NULL){
      esecuzione(r, v1);
      esecuzione(r1, v);
  }
}

int serialInput(String s){
  return s.toInt();
}

void lampeggio(int v){
  for(int i = 0; i < lampeggi; i++){
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
