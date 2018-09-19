#include "clinvar.h"

ClinVar::ClinVar(const ClinVar& orig){
    EnfDB =  orig.EnfDB;
    IDenf_map =  orig.IDenf_map;
    IDm_map =  orig.IDm_map;
    gen_map =  orig.gen_map;
    mutDB =  orig.mutDB;
}

const mutacion& ClinVar::iterator::operator*(){
    return *it;
}

bool ClinVar::iterator::operator ! =  (const iterator& x) const{
    return it ! =  x.it;
}

ClinVar::iterator& ClinVar::iterator::operator++(){
    it++;
    return *this;
}

ClinVar::iterator ClinVar::iterator::operator++(int){
    ClinVar::iterator r_it =  *this;
    ++(this->it);
    return r_it;
}

const mutacion& ClinVar::gen_iterator::operator*(){
    return **itlist;
}

bool ClinVar::gen_iterator::operator ! =  (const gen_iterator& x) const{
    return itlist ! =  x.itlist;
}

ClinVar::gen_iterator& ClinVar::gen_iterator::operator++(){
    itlist++;
    if(itlist ! =  itmap->second.end())
        return *this;
    else{
        itmap++;
        itlist =  itmap->second.begin();
    }
    
    return *this;
}

ClinVar::gen_iterator ClinVar::gen_iterator::operator++(int){
    ClinVar::gen_iterator it =  *this;
    itlist++;
    if(itlist ! =  (itmap->second.end()))
        return it;
    else{
        itmap++;
        if(itmap ! =  this->ptrclinvar->gen_map.end()){
            itlist =  itmap->second.begin();
            return it;
        }
        itlist =  itmap->second.end();
    }
    return it;
}

ClinVar::iterator ClinVar::begin(){
    ClinVar::iterator i_it;
    i_it.it =  mutDB.begin();
    
    return i_it;
}

ClinVar::iterator ClinVar::end(){
    ClinVar::iterator r_it;
    r_it.it = mutDB.end();
    
    return r_it;
}

ClinVar::iterator ClinVar::lower_bound(string cromosoma, unsigned int posicion){
    ClinVar::iterator l_it;
    mutacion m_aux;
    m_aux.setChr(cromosoma); m_aux.setPos(posicion);
    
    l_it.it =  mutDB.lower_bound(m_aux);
    return l_it;
}

ClinVar::iterator ClinVar::upper_bound(string cromosoma, unsigned int posicion){
    ClinVar::iterator r_it;
    mutacion m_aux;
    m_aux.setChr(cromosoma);
    m_aux.setPos(posicion);
    
    r_it.it =  mutDB.upper_bound(m_aux);
    return r_it;
}

ClinVar::enfermedad_iterator ClinVar::ebegin(){
    return EnfDB.begin();
}

ClinVar::enfermedad_iterator ClinVar::eend(){
    return EnfDB.end();
}

ClinVar::gen_iterator ClinVar::gbegin(){
    ClinVar::gen_iterator gen;
    gen.ptrclinvar = this;
    gen.itmap =  gen.ptrclinvar->gen_map.begin();
    gen.itlist =  gen.itmap->second.begin();
    
    return gen;
}

ClinVar::gen_iterator ClinVar::gend() {
    ClinVar::gen_iterator gen_r;
    gen_r.ptrclinvar = this;
    gen_r.itmap =  gen_r.ptrclinvar->gen_map.end();
    gen_r.itlist =  gen_r.itmap->second.end();
    
    return gen_r;
}

int ClinVar::countMut() const{
    return mutDB.size();
}

int ClinVar::countenf() const {
    return EnfDB.size();
}

int ClinVar::countenfa() const {
    return IDenf_map.size();
}

int ClinVar::countGen() const {
    return gen_map.size();
}

void ClinVar::load(string nombreDB){
    ifstream fe;
    string cadena;

    cout << "Abrimos "<< nombreDB << endl;
    fe.open(nombreDB.c_str(), ifstream::in);
    if(fe.fail()){
        cerr << "Error al abrir el fichero " << nombreDB << endl;
    }
    else {
    //leo la cabecera del fichero (líneas que comienzan con #)
    do{
      getline(fe,cadena,'\n');
    }while (cadena.find('#') ! =  string::npos && !fe.eof());

    while (!fe.eof()){
        mutacion mut  =  mutacion(cadena);
        //cout << mut<< endl;
        // Insertar mutación en el conjunto
        insert(mut);
        getline(fe,cadena,'\n');
    }
    fe.close();
    } // else
    fe.close();
}

void ClinVar::insert(const mutacion& x){
    set<mutacion>::iterator ite =  mutDB.insert(x).first;
    IDm_map[x.getID()] = ite;
    
    vector<enfermedad> enfermedades_x =  x.getEnfermedades();
    
    for(int i = 0; i<enfermedades_x.size(); i++){
        enfermedad enf_aux = enfermedades_x.at(i);
        EnfDB[enf_aux.getID()] =  enf_aux;
        IDenf_map.insert(pair<IDenf, set<mutacion>::iterator>(enf_aux.getID(), ite));
    }
    
    vector<string> genes =  x.getGenes();
    for(int i = 0; i<genes.size(); i++){
        string gen =  genes.at(i);
        gen_map[gen].push_back(ite);
    }
}

vector<enfermedad> ClinVar::getEnfermedades(const mutacion& mut) {
    vector<enfermedad> v_enf;
    for(multimap<IDenf,set<mutacion>::iterator>::const_iterator it = IDenf_map.begin(); it ! =   IDenf_map.end(); it++)
        if(*(it->second) =  = mut)
            v_enf.push_back(EnfDB[it->first]);
    return v_enf;
}

list<IDenf> ClinVar::getEnfermedades(string keyword) const{
    list<IDenf> l_enf;
    
    for(map<IDenf,enfermedad>::const_iterator it = EnfDB.begin(); it ! =  EnfDB.end(); it++)
        if(it->second.nameContains(keyword))
            l_enf.push_back(it->first);
    
    return l_enf;
}

set<IDmut> ClinVar::getMutacionesEnf(IDenf ID) const{
    set<IDmut> muts;
    for(multimap<IDenf,set<mutacion>::iterator>::const_iterator it = IDenf_map.begin(); it ! =  IDenf_map.end(); it++)
        if(it->first =  = ID)
            muts.insert(it->second->getID());
    return muts;
}

set<IDmut> ClinVar::getMutacionesGen(IDgen ID) const{
    set<IDmut> muts;
    for(map<IDgen, list< set<mutacion>::iterator> >::const_iterator it = gen_map.begin(); it ! =  gen_map.end(); it++)
        if(it->first =  = ID){
            list< set<mutacion>::iterator> laux = it->second;
            for(list< set<mutacion>::iterator>::const_iterator it_l = laux.begin(); it_l ! =  laux.end(); it_l++)
                muts.insert((*(*it_l)).getID());
        }
            
    return muts;
}

set<mutacion,ProbMutaciones> ClinVar::topKMutaciones(int k, string keyword){
    set<mutacion,ProbMutaciones> set_probability;
    list<IDenf> l_enf =  getEnfermedades(keyword);
    set<mutacion> mut_asociadas;
    
    for(list<IDenf>::const_iterator l_it =  l_enf.begin(); l_it ! =  l_enf.end(); l_it++){
        set<IDmut> set_aux = getMutacionesEnf(*l_it);
        for(set<IDmut>::iterator it_aux =  set_aux.begin(); it_aux ! =  set_aux.end(); it_aux++)
            mut_asociadas.insert(*find_Mut(*it_aux));
    }
    
    set<mutacion>::const_iterator it_mut_a =  mut_asociadas.begin();
    priority_queue<mutacion, vector<mutacion>, ProbMutaciones> p;
    for(int i = 0; i<k; i++){
        if(it_mut_a  ! =   mut_asociadas.end()){
            p.push(*it_mut_a);
            it_mut_a++;
        }
    }
 
    ProbMutaciones comp;
    
    while(it_mut_a  ! =   mut_asociadas.end()){
        if(comp(*it_mut_a,p.top())){
            p.pop();
            p.push(*it_mut_a);
            it_mut_a++;
        }
        else
            it_mut_a++;
    }
    
    while(!p.empty()){
        set_probability.insert(p.top());
        p.pop();
    }
    
    return set_probability;
}

ClinVar::iterator ClinVar::find_Mut(IDmut ID) const{
    ClinVar::iterator r_it;
    unordered_map<IDmut,set<mutacion>::iterator>::const_iterator it_m = IDm_map.find(ID);
    r_it.it =  it_m->second;
    
    return r_it;
}

ClinVar::enfermedad_iterator ClinVar::find_Enf(IDenf ID)  {
    return EnfDB.find(ID);
}