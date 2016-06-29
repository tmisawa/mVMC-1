/*-------------------------------------------------------------
 * Variational Monte Carlo
 * Allocate and free memory for global array
 *-------------------------------------------------------------
 * by Satoshi Morita and Ryui Kaneko
 *-------------------------------------------------------------*/

void SetMemoryDef();
void FreeMemoryDef();
void SetMemory();
void FreeMemory();

void SetMemoryDef() {  
  int i;
  int *pInt;
  double *pDouble;

  /* Int */
  LocSpn = (int*)malloc(sizeof(int)*NTotalDefInt);
  pInt = LocSpn + Nsite;

  Transfer = (int**)malloc(sizeof(int*)*NTransfer);
  for(i=0;i<NTransfer;i++) {
    Transfer[i] = pInt;
    pInt += 3;
  }

  CoulombIntra = pInt;
  pInt += NCoulombIntra;

  CoulombInter = (int**)malloc(sizeof(int*)*NCoulombInter);
  for(i=0;i<NCoulombInter;i++) {
    CoulombInter[i] = pInt;
    pInt += 2;
  }

  HundCoupling = (int**)malloc(sizeof(int*)*NHundCoupling);
  for(i=0;i<NHundCoupling;i++) {
    HundCoupling[i] = pInt;
    pInt += 2;
  }

  PairHopping = (int**)malloc(sizeof(int*)*NPairHopping);
  for(i=0;i<NPairHopping;i++) {
    PairHopping[i] = pInt;
    pInt += 2;
  }

  ExchangeCoupling = (int**)malloc(sizeof(int*)*NExchangeCoupling);
  for(i=0;i<NExchangeCoupling;i++) {
    ExchangeCoupling[i] = pInt;
    pInt += 2;
  }

  GutzwillerIdx = pInt;
  pInt += Nsite;

  JastrowIdx = (int**)malloc(sizeof(int*)*Nsite);
  for(i=0;i<Nsite;i++) {
    JastrowIdx[i] = pInt;
    pInt += Nsite;
  }

  DoublonHolon2siteIdx = (int**)malloc(sizeof(int*)*NDoublonHolon2siteIdx);
  for(i=0;i<NDoublonHolon2siteIdx;i++) {
    DoublonHolon2siteIdx[i] = pInt;
    pInt += 2*Nsite;
  }

  DoublonHolon4siteIdx = (int**)malloc(sizeof(int*)*NDoublonHolon4siteIdx);
  for(i=0;i<NDoublonHolon4siteIdx;i++) {
    DoublonHolon4siteIdx[i] = pInt;
    pInt += 4*Nsite;
  }

  OrbitalIdx = (int**)malloc(sizeof(int*)*Nsite);
  for(i=0;i<Nsite;i++) {
    OrbitalIdx[i] = pInt;
    pInt += Nsite;
  }

  OrbitalSgn = (int**)malloc(sizeof(int*)*Nsite);
  for(i=0;i<Nsite;i++) {
    OrbitalSgn[i] = pInt;
    pInt += Nsite;
  }

  QPTrans = (int**)malloc(sizeof(int*)*NQPTrans);
  for(i=0;i<NQPTrans;i++) {
    QPTrans[i] = pInt;
    pInt += Nsite;
  }

  QPTransSgn = (int**)malloc(sizeof(int*)*NQPTrans);
  for(i=0;i<NQPTrans;i++) {
    QPTransSgn[i] = pInt;
    pInt += Nsite;
  }

  CisAjsIdx = (int**)malloc(sizeof(int*)*NCisAjs);
  for(i=0;i<NCisAjs;i++) {
    CisAjsIdx[i] = pInt;
    pInt += 3;
  }

  CisAjsCktAltIdx = (int**)malloc(sizeof(int*)*NCisAjsCktAlt);
  for(i=0;i<NCisAjsCktAlt;i++) {
    CisAjsCktAltIdx[i] = pInt;
    pInt += 8;
  }

  CisAjsCktAltDCIdx = (int**)malloc(sizeof(int*)*NCisAjsCktAltDC);
  for(i=0;i<NCisAjsCktAltDC;i++) {
    CisAjsCktAltDCIdx[i] = pInt;
    pInt += 6;
  }

  InterAll = (int**)malloc(sizeof(int*)*NInterAll);
  for(i=0;i<NInterAll;i++) {
    InterAll[i] = pInt;
    pInt += 6;
  }

  QPOptTrans = (int**)malloc(sizeof(int*)*NQPOptTrans);
  for(i=0;i<NQPOptTrans;i++) {
    QPOptTrans[i] = pInt;
    pInt += Nsite;
  }

  QPOptTransSgn = (int**)malloc(sizeof(int*)*NQPOptTrans);
  for(i=0;i<NQPOptTrans;i++) {
    QPOptTransSgn[i] = pInt;
    pInt += Nsite;
  }

  OptFlag = pInt;

  /* Double */
  ParaTransfer = (double*)malloc(sizeof(double)*(NTotalDefDouble));
  pDouble = ParaTransfer + NTransfer;

  ParaCoulombIntra = pDouble;
  pDouble += NCoulombIntra;

  ParaCoulombInter = pDouble;
  pDouble += NCoulombInter;

  ParaHundCoupling = pDouble;
  pDouble += NHundCoupling;

  ParaPairHopping = pDouble;
  pDouble +=  NPairHopping;

  ParaExchangeCoupling = pDouble;
  pDouble +=  NExchangeCoupling;
  
  ParaQPTrans = pDouble;
  pDouble +=  NQPTrans;

  ParaInterAll = pDouble;
  pDouble +=  NInterAll;
  
  ParaQPOptTrans = pDouble;

  return;
}

void FreeMemoryDef() {
  free(ParaTransfer);

  free(QPOptTransSgn);
  free(QPOptTrans);
  free(InterAll);
  free(CisAjsCktAltDCIdx);
  free(CisAjsCktAltIdx);
  free(CisAjsIdx);
  free(QPTransSgn);
  free(QPTrans);
  free(OrbitalIdx);
  free(DoublonHolon4siteIdx);
  free(DoublonHolon2siteIdx);
  free(JastrowIdx);
  free(ExchangeCoupling);
  free(PairHopping);
  free(HundCoupling);
  free(CoulombInter);
  free(Transfer);
  free(LocSpn);

  return;
}

void SetMemory() {

  /***** Variational Parameters *****/
  Para = (double*)malloc(sizeof(double)*(NPara));
  Proj = Para;
  Slater = Para + NProj;
  OptTrans = Para + NProj + NSlater;

  /***** Electron Configuration ******/
  EleIdx = (int*)malloc(sizeof(int)*( NVMCSample*2*Ne ));
  EleCfg = (int*)malloc(sizeof(int)*( NVMCSample*2*Nsite ));
  EleNum = (int*)malloc(sizeof(int)*( NVMCSample*2*Nsite ));
  EleProjCnt = (int*)malloc(sizeof(int)*( NVMCSample*NProj ));
  logSqPfFullSlater = (double*)malloc(sizeof(double)*(NVMCSample));

  TmpEleIdx = (int*)malloc(sizeof(int)*(2*Ne+2*Nsite+2*Nsite+NProj));
  TmpEleCfg = TmpEleIdx + 2*Ne;
  TmpEleNum = TmpEleCfg + 2*Nsite;
  TmpEleProjCnt = TmpEleNum + 2*Nsite;

  BurnEleIdx = (int*)malloc(sizeof(int)*(2*Ne+2*Nsite+2*Nsite+NProj));
  BurnEleCfg = BurnEleIdx + 2*Ne;
  BurnEleNum = BurnEleCfg + 2*Nsite;
  BurnEleProjCnt = BurnEleNum + 2*Nsite;

  /***** Slater Elements ******/
  SlaterElm = (double*)malloc( sizeof(double)*(NQPFull*(2*Nsite)*(2*Nsite)) );

  InvM = (double*)malloc( sizeof(double)*(NQPFull*(Nsize*Nsize+1)) );
  PfM = InvM + NQPFull*Nsize*Nsize;

  /***** Quantum Projection *****/
  QPFullWeight = (double*)malloc(sizeof(double)*(NQPFull+NQPFix+5*NSPGaussLeg));
  QPFixWeight= QPFullWeight + NQPFull;
  SPGLCos    = QPFullWeight + NQPFull + NQPFix;
  SPGLSin    = SPGLCos + NSPGaussLeg;
  SPGLCosSin = SPGLCos + 2*NSPGaussLeg;
  SPGLCosCos = SPGLCos + 3*NSPGaussLeg;
  SPGLSinSin = SPGLCos + 4*NSPGaussLeg;

  /***** Stocastic Reconfiguration *****/
  if(NVMCCalMode==0){
    SROptOO  = (double*)malloc( sizeof(double)*(SROptSize*(SROptSize+4)) );
    SROptHkO = SROptOO  + SROptSize*SROptSize;
    SROptHcO = SROptHkO + SROptSize;
    SROptHO  = SROptHcO  + SROptSize;
    SROptO   = SROptHO  + SROptSize;

    if(NStoreO!=0){
      SROptO_Store = (double*)malloc( sizeof(double)*(SROptSize*NVMCSample) );
    }
    SROptData = (double*)malloc( sizeof(double)*(NSROptItrSmp*(2+NPara)) );
  }

  /***** Physical Quantity *****/
  if(NVMCCalMode==1){
    PhysCisAjs  = (double*)malloc(sizeof(double)
                    *(2*NCisAjs+NCisAjsCktAlt+NCisAjsCktAltDC));
    PhysCisAjsCktAlt   = PhysCisAjs       + NCisAjs;
    PhysCisAjsCktAltDC = PhysCisAjsCktAlt + NCisAjsCktAlt;
    LocalCisAjs = PhysCisAjsCktAltDC + NCisAjsCktAltDC;
    if(NLanczosMode>0){
      if(NStoreO!=0){
        LSHH_Store = (double*)malloc( sizeof(double)*((3+NSplitSize)*NVMCSample) );
        w_Store   = LSHH_Store;
        H_Store   = LSHH_Store + NVMCSample;
        HcH_Store = LSHH_Store + 2*NVMCSample;
        HkH_Store = LSHH_Store + 3*NVMCSample;
        
        LSHHHH = (double*)malloc( sizeof(double)*((3+NSplitSize)*(3+NSplitSize)) );
      }
      
      QQQQ = (double*)malloc(sizeof(double)
        *(NLSHam*NLSHam*NLSHam*NLSHam + NLSHam*NLSHam) );
      LSLQ = QQQQ + NLSHam*NLSHam*NLSHam*NLSHam;
      if(NLanczosMode>1){
        QCisAjsQ = (double*)malloc(sizeof(double)
          *(NLSHam*NLSHam*NCisAjs + NLSHam*NLSHam*NCisAjsCktAlt + NLSHam*NCisAjs) );
        QCisAjsCktAltQ = QCisAjsQ + NLSHam*NLSHam*NCisAjs;
        LSLCisAjs = QCisAjsCktAltQ + NLSHam*NLSHam*NCisAjsCktAlt;
      }
    }
  }

  initializeWorkSpaceAll();
  return;
}

void FreeMemory() {
  FreeWorkSpaceAll();

  if(NVMCCalMode==1){
    free(PhysCisAjs);
    if(NLanczosMode>0){
      free(QQQQ);
      if(NLanczosMode>1){
        free(QCisAjsQ);
      }
    }
  }

  if(NVMCCalMode==0){
    free(SROptData);
    free(SROptOO);
  }

  free(QPFullWeight);

  free(InvM);
  free(SlaterElm);

  free(BurnEleIdx);
  free(TmpEleIdx);
  free(logSqPfFullSlater);
  free(EleProjCnt);
  free(EleIdx);
  free(EleCfg);

  free(Para);

  return;
}