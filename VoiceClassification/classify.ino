#define MIC_INPUT                   A2
#define RXLED                       17
#define TXLED                       30

#define SIZE                        5504
#define ADC_TIMER_MS                0.35
#define AVG_SHIFT                   5
#define AVG_SIZE                    (int) pow(2, AVG_SHIFT)
#define SIZE_AFTER_FILTER           (int) SIZE / AVG_SIZE

/*---------------------------*/
/*      CODE BLOCK PCA1      */
/*---------------------------*/

#define SNIPPET_SIZE                80
#define PRELENGTH                   5
#define THRESHOLD                   0.5
#define BASIS_DIM                   3

#define EUCLIDEAN_THRESHOLD         0.05
#define LOUDNESS_THRESHOLD          50


/*---------------------------*/
/*      CODE BLOCK PCA2      */
/*---------------------------*/

float pca_vec1[80] = {0.015386892072252642, 0.010547182250701614, 0.01283279071641219, 0.008972414726049163, 0.07175890381259362, 0.34877631563777517, 0.39937931357799383, 0.35683970760573064, 0.30440270006890047, 0.28145643793941966, 0.2586508983034449, 0.21923234714042436, 0.17161796339416188, 0.13598509785971863, 0.1010373102464148, 0.12049096831936167, 0.09046058202884606, 0.08247057751657698, 0.06489627809146162, 0.025672515977023167, 0.014162330375120965, -0.011287347627025924, -0.03489607957014929, -0.030155655436216965, -0.04634969291202541, -0.03374070595641963, -0.028370610098527007, -0.010165881387226688, -0.011136461459825239, -0.0320593377842264, -0.03820103248427972, -0.0403715024313049, -0.07772244435382049, -0.09139071342494141, -0.09438842173162258, -0.10328564819812544, -0.1128900114277524, -0.10874958368343601, -0.10929476067399196, -0.10256650681643038, -0.09674981560896283, -0.09552350485697861, -0.08292190844451991, -0.06865467416467161, -0.06143711308614034, -0.04753329676691017, -0.03780929267676858, -0.034802358338373966, -0.0310235508107593, -0.029157967464083643, -0.030418044983961157, -0.03194573374198646, -0.04188896988841404, -0.04872485191449025, -0.058059066232078044, -0.061843203820894865, -0.07269240098203734, -0.0698637068187079, -0.07331958697997933, -0.06657542788395257, -0.06929961500229652, -0.06788582915455449, -0.05675172126073647, -0.05830535923615836, -0.054949349968651987, -0.05602242220840779, -0.05570195191963731, -0.05730025712802781, -0.04786257656573188, -0.04410432128232699, -0.04040569296121004, -0.037665387985091545, -0.027058200948820926, -0.03268536988380881, -0.02802452396122854, -0.027133484380550563, -0.022788052796073696, -0.02397994321064973, -0.014835638673737718, -0.014302956210663773};
float pca_vec2[80] = {-0.025695799136122518, -0.017087527790553003, -0.0014709433414107353, 0.03752554125831775, -0.003280489192738767, -0.15348621059837803, -0.17013022814447054, -0.15117230945170232, -0.07286782644890975, -0.05635924298122596, -0.03053461886859429, 0.00740305741807982, 0.06620964523176018, 0.1131397759887007, 0.13073051031955, 0.13252578884701213, 0.13903665280940142, 0.16433912141980614, 0.17644879984718984, 0.17392645271987792, 0.20504311423189, 0.20549069407767456, 0.20397119102449457, 0.1964014416992578, 0.21589783995143916, 0.22240992199521725, 0.194447460065654, 0.22742691133497384, 0.21240592019294643, 0.19402656910552987, 0.16008056488092934, 0.13605971512342485, 0.0951977998314599, 0.05053486754558301, -0.021730691233295858, -0.07682090113931507, -0.081223426005792, -0.10746472177585364, -0.12572286602551022, -0.1465305009949177, -0.14595148063216734, -0.1393055430581773, -0.1405209710453085, -0.13072126767087117, -0.10137535209507627, -0.08181702600319607, -0.059647181925024904, -0.03700852822110502, -0.030857679418840253, -0.030113394309808316, -0.01580918124224387, -0.02833093361849521, -0.03646631000692781, -0.03705102333771359, -0.0923384640889316, -0.09285153232495094, -0.09627097800152837, -0.09235942350715988, -0.07711933093415967, -0.06585216505816455, -0.043904650574613936, -0.016435308212490812, -0.02925990739775271, -0.022407581633298947, -0.019807695886109766, -0.02298758327760374, -0.022558021722663888, -0.01762315486267525, -0.01921011723597932, -0.018153386448318827, -0.03858156106386387, -0.033352124165722974, -0.05757127255948089, -0.04652051446604681, -0.06751326840834806, -0.08171480709722657, -0.08625339657878503, -0.08403083760937381, -0.08512113080743511, -0.07432696728373915};
float pca_vec3[80] = {0.020074148581918194, 0.046670409034902605, 0.05674471808577686, 0.0734286561383144, 0.059991086757127166, 0.05888257166187649, 0.07147861338289842, 0.039650629351821204, 0.015700773211057742, -0.013386806801878438, -0.02915741573628204, -0.037104753820627424, -0.04332479562775684, -0.04702930267597158, -0.054183040481099266, -0.03467724812135956, -0.04060400659034095, -0.02969062103631764, -0.027870280320000346, -0.03299099826154886, -0.0504122647662038, -0.03190831586074287, -0.013884350615039913, 0.013278451548291674, 0.01861413953565025, 0.06092544685293896, 0.09356745403303551, 0.11076549666568616, 0.12017037280667063, 0.07202981271593864, 0.06098021741080885, 0.05519560853450787, 0.02115467286070933, 0.003009371563468211, -0.0006236233236064445, -0.003156655039913291, 0.002965549359248164, 0.019996125966996743, 0.03589346009691818, 0.05785056141462987, 0.06277130180764309, 0.08559621889735798, 0.10939054311613472, 0.13699630247733607, 0.1557714342185185, 0.18156208023057127, 0.198920949892743, 0.2155499218609976, 0.2127761308766049, 0.19751498631646422, 0.173275754364401, 0.14710869931214338, 0.12640356051570123, 0.10982132769098746, 0.07081456370151737, 0.04837858342529236, 0.04860745131192053, 0.04701575808666676, 0.02877485099011657, 0.006696593737338754, -0.024953363458393732, -0.060674839553952024, -0.06821482660968622, -0.10449486215107814, -0.1309469899425048, -0.15160195715492705, -0.17479837523823413, -0.194219543027781, -0.2022116708995404, -0.22176518719255958, -0.22985775021592536, -0.21418994176025583, -0.20446486087660679, -0.1981337776017324, -0.19926906931321725, -0.17719139604808112, -0.16239989455150283, -0.14714311706063607, -0.11048734189068034, -0.08574211677566451};
float projected_mean_vec[3] = {0.04589004012639152, 0.010641241893221801, -0.0018385645993100927};
float centroid1[3] = {-0.03648548479074178, -0.019589882512418715, -0.023134135691693928};
float centroid2[3] = {-0.004545280218482427, 0.032071993308636304, -0.00896633550402186};
float centroid3[3] = {0.08032380552085047, -0.006961535592259866, 0.002516838171324831};
float centroid4[3] = {-0.039293040511626326, -0.005520575203957736, 0.029583633024390956};
float* centroids[4] = { // DO NOT DELETE THIS CHUNK
  (float *) &centroid1, (float *) &centroid2,
  (float *) &centroid3, (float *) &centroid4
};

//print("Paste the code below into 'CODE BLOCK PCA2':")
//print("")
//print(utils.format_array_c("pca_vec1", new_basis[:, 0]))
//print(utils.format_array_c("pca_vec2", new_basis[:, 1]))
//if new_basis.shape[1] == 3:
//    print(utils.format_array_c("pca_vec3", new_basis[:, 2]))
//print(utils.format_array_c("projected_mean_vec", projected_mean_vec))
//print(utils.format_array_c("centroid1", centroids[0]))
//print(utils.format_array_c("centroid2", centroids[1]))
//print(utils.format_array_c("centroid3", centroids[2]))
//print(utils.format_array_c("centroid4", centroids[3]))
/*---------------------------*/
/*---------------------------*/
/*---------------------------*/

//data array and index pointer
int16_t out[SIZE_AFTER_FILTER] = {0};
volatile int re_pointer = 0;

int16_t re0[AVG_SIZE] = {0};
int16_t re1[AVG_SIZE] = {0};
int write_arr = 0;

// this function allows us to get the correct array to save data to
// we are using a concept known as "pointer juggling" to save memory
int16_t * get_re(int loc){
  switch(loc){
    case 0:
      return re0;
    case 1:
      return re1;
    default:
      return re0;
  }
}

float result[SNIPPET_SIZE] = {0};
float proj1 = 0;
float proj2 = 0;
float proj3 = 0;

/*---------------------------*/
/*       Norm functions      */
/*---------------------------*/

// Compute the L2 norm of (dim1, dim2) and centroid
// input: dim1: 1st dimension coordinate
//        dim2: 2nd dimension coordinate
//        centroid: size-2 array containing centroid coordinates
// output: L2 norm (Euclidean distance) between point and centroid
float l2_norm(float dim1, float dim2, float* centroid) {
  return sqrt(pow(dim1-centroid[0],2) + pow(dim2-centroid[1],2));
}

// Compute the L2 norm of (dim1, dim2, dim3) and centroid
// input: dim1: 1st dimension coordinate
//        dim2: 2nd dimension coordinate
//        dim3: 3rd dimension coordinate
//        centroid: size-3 array containing centroid coordinates
// output: L2 norm (Euclidean distance) between point and centroid
float l2_norm3(float dim1, float dim2, float dim3, float* centroid) {
  return sqrt(pow(dim1-centroid[0],2) + pow(dim2-centroid[1],2) + pow(dim3-centroid[2],2));
}

void setup(void) {
  pinMode(MIC_INPUT, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RXLED, OUTPUT);
  pinMode(TXLED, OUTPUT);
  delay(1000);

  re_pointer = 0;
      
  cli();
 
  //set timer1 interrupt at 1Hz * SAMPLING INTERVAL / 1000
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15.624 * ADC_TIMER_MS;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  
  sei();

  Serial.begin(38400);
  delay(1000);
}


void loop(void) {
  if (re_pointer%AVG_SIZE == 0 && re_pointer <= SIZE){
    write_arr = !write_arr;
    envelope(get_re(!write_arr), out, re_pointer>>AVG_SHIFT);
  }
  if (re_pointer == (int) (SIZE / 3)) {
    digitalWrite(TXLED, LOW);
  }
  if (re_pointer == (int) (SIZE * 2 / 3)) {
    digitalWrite(RXLED, LOW);
  }
  if (re_pointer == SIZE) {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(TXLED, HIGH);
    digitalWrite(RXLED, HIGH);
    
    // Apply enveloping function and get snippet with speech.
    // Do classification only if loud enough.
    if(envelope(out, result)) {

      // Reset projection result variables declared above
      proj1 = 0;
      proj2 = 0;
      proj3 = 0;

      /*---------------------------*/
      /*      CODE BLOCK PCA3      */
      /*---------------------------*/

      // Project 'result' onto the principal components
      // Hint: 'result' is an array
      // Hint: the principal components are unit norm
      // Hint: do this entire operation in 1 loop by replacing the '...'
      // YOUR CODE HERE
      for (int i = 0; i < SNIPPET_SIZE; i++) {
        
        proj1 += pca_vec1[i]* result[i];
        proj2 += pca_vec2[i]* result[i];
        proj3 += pca_vec3[i]* result[i];
      }

      // Demean the projection
      proj1 -= projected_mean_vec[0];
      proj2 -= projected_mean_vec[1];
      proj3 -= projected_mean_vec[2];

      // Classification
      // Use the function 'l2_norm3' defined above
      // ith centroid: 'centroids[i]'
      float best_dist = 999999;
      int best_index = -1;
      // YOUR CODE HERE
      float x[4];
      for (int i = 0; i < 4; i++){
       if (l2_norm3(proj1, proj2, proj3, centroids[i]) < best_dist){
        best_dist = l2_norm3(proj1, proj2, proj3, centroids[i]);
        best_index = i;
       }
      }

      
      // Compare 'best_dist' against the 'EUCLIDEAN_THRESHOLD' and print the result
      // If 'best_dist' is less than the 'EUCLIDEAN_THRESHOLD', the recording is a word
      // Otherwise, the recording is noise
      // YOUR CODE HERE

      if(best_dist < EUCLIDEAN_THRESHOLD){
        //[congrat, unicorn, stop, roni]
        Serial.println(best_index);
        Serial.println("working.");
      }
      /*---------------------------*/
      /*---------------------------*/
      /*---------------------------*/
   } else {
     Serial.println("Below LOUDNESS_THRESHOLD.");
   }

    delay(2000);
    re_pointer = 0;
  }
}

/*---------------------------*/
/*     Helper functions      */
/*---------------------------*/


void reset_blinker(void) {
  pinMode(RXLED, OUTPUT);
  pinMode(TXLED, OUTPUT);
  digitalWrite(RXLED, HIGH);
  delay(100);
  digitalWrite(RXLED, LOW);
  digitalWrite(TXLED, HIGH);
  delay(100);
  digitalWrite(RXLED, HIGH);
  digitalWrite(TXLED, LOW);
  delay(100);
  digitalWrite(RXLED, HIGH);
  digitalWrite(TXLED, HIGH);
  delay(100);
  digitalWrite(TXLED, HIGH);
}

void envelope(int16_t* data, int16_t* data_out, int index){
  int32_t avg = 0;
  for (int i = 0; i < AVG_SIZE; i++) {
      avg += data[i];
  }
  
  avg = avg >> AVG_SHIFT;
  data_out[index] = abs(data[0] - avg);  
  
  for (int i = 1; i < AVG_SIZE; i++) {
      data_out[index] += abs(data[i] - avg);
  }
}

// Enveloping function with thresholding and normalizing,
// returns snippet of interest (containing speech)
bool envelope(int* data, float* data_out) {
  float maximum = 0;
  int32_t total = 0;
  int block;

  // Apply enveloping filter while finding maximum value
  for (block = 0; block < SIZE_AFTER_FILTER; block++) {
    if (data[block] > maximum) {
      maximum = data[block];
    }
  }

  // If not loud enough, return false
  if (maximum < LOUDNESS_THRESHOLD) {
    Serial.println(maximum);
    return false;
  }

  // Determine threshold
  float thres = THRESHOLD * maximum;

  // Figure out when interesting snippet starts and write to data_out
  block = PRELENGTH;
  while (data[block++] < thres && block < SIZE_AFTER_FILTER);
  if (block > SIZE_AFTER_FILTER - SNIPPET_SIZE) {
    block = SIZE_AFTER_FILTER - SNIPPET_SIZE;
  }
  for (int i = 0; i < SNIPPET_SIZE; i++) {
    data_out[i] = data[block-PRELENGTH+i];
    total += data_out[i];
  }

  // Normalize data_out
  for (int i = 0; i < SNIPPET_SIZE; i++) {
    data_out[i] = data_out[i] / total;
  }

  return true;
}
/*---------------------------*/
/*    Interrupt functions    */
/*---------------------------*/


ISR(TIMER1_COMPA_vect){//timer1 interrupt 8Khz toggles pin 13 (LED)
  if (re_pointer < SIZE) {
    digitalWrite(RXLED, LOW);
    get_re(write_arr)[re_pointer%AVG_SIZE] = (analogRead(MIC_INPUT) >> 4) - 128;
    re_pointer += 1;
  }
}