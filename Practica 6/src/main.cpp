#include <cstdlib>
#include <iostream>
#include "clinvar.h"

using namespace std;

int main(int argc, char** argv) {
    ClinVar prueba;
    
    prueba.load("/dats/clinvar_20160831.vcf");
    cout << prueba.countMut() << endl;
    
    
    // Mutaciones ordenadas por id/posición 
    for(ClinVar::iterator it=prueba.begin(); it!= prueba.end(); it++){
        cout << *it << "\n";
    }
   
    for(ClinVar::gen_iterator it_g=prueba.gbegin(); it_g!= prueba.gend(); it_g++){
        cout << *it_g << "\n";
    }
    
    // Acceso a mutaciones por id(eficiente)
    cout << *prueba.find_Mut("rs781514122");
    
    //Muaciones afectan a gen
    set<IDmut> muts_gen= prueba.getMutacionesGen("SLC25A22:79751");
    for(set<IDmut>::const_iterator s_it= muts_gen.begin(); s_it!=muts_gen.end(); s_it++)
        cout << *s_it << endl;
    
    // Base datos de enfermedades
    for(ClinVar::enfermedad_iterator it_enf=prueba.ebegin(); it_enf!= prueba.eend(); it_enf++){
        cout << it_enf->second.getName() << "\n";
    }
    
    set<IDmut> muts_enf= prueba.getMutacionesEnf("C0270855:609304:1935:44423001");
    for(set<IDmut>::const_iterator s_it= muts_enf.begin(); s_it!=muts_enf.end(); s_it++)
        cout << *s_it << endl;
    
    list<IDenf> l_enf= prueba.getEnfermedades("Mental_retardation");
    for(list<IDenf>::iterator it=l_enf.begin(); it!=l_enf.end(); it++)
        cout << *it << endl;
    
    vector<enfermedad> enf_asociadas;
    string m="1	1050446	rs17160775	G	A	.	.	RS=17160775;RSPOS=1050446;dbSNPBuildID=123;SSR=0;SAO=1;VP=0x050360000a05150536100100;GENEINFO=AGRN:375790;WGT=1;VC=SNV;PM;S3D;SLO;NSM;REF;ASP;VLD;G5;HD;GNO;KGPhase1;KGPhase3;LSD;CLNALLE=1;CLNHGVS=NC_000001.11:g.1050446G>A;CLNSRC=.;CLNORIGIN=1;CLNSRCID=.;CLNSIG=3;CLNDSDB=MedGen;CLNDSDBID=CN169374;CLNDBN=not_specified;CLNREVSTAT=no_criteria;CLNACC=RCV000116274.2;CAF=0.9541,0.04593;COMMON=1";
    mutacion mut_p=m;
    enf_asociadas= prueba.getEnfermedades(mut_p);
    
    for(int i=0; i<enf_asociadas.size(); i++)
        cout << enf_asociadas.at(i).getName() << endl;
    
    // TopKmutaciones
    
    set<mutacion,ProbMutaciones> set_prob=prueba.topKMutaciones(10, "not_specified");
    for(set<mutacion,ProbMutaciones>::const_iterator set_p_it= set_prob.begin(); set_p_it!=set_prob.end(); set_p_it++)
        cout << *set_p_it << endl;
    
    return 0;
}

