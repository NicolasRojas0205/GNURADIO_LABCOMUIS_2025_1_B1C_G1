#ifndef MODULACIONAM_1_HPP
#define MODULACIONAM_1_HPP
/********************
GNU Radio C++ Flow Graph Header File

Title: Not titled yet
Author: estudiante
GNU Radio version: v3.10.11.0-89-ga17f69e7
********************/

/********************
** Create includes
********************/
#include <gnuradio/top_block.h>
#include <string>
#include <gnuradio/blocks/add_const_ff.h>
#include <gnuradio/blocks/float_to_complex.h>
#include <gnuradio/blocks/multiply_const.h>
#include <gnuradio/blocks/null_source.h>


#include <boost/program_options.hpp>

using namespace gr;


class modulacionAM_1 : public hier_block2 {

private:


    blocks::null_source::sptr blocks_null_source_0;
    blocks::multiply_const_cc::sptr blocks_multiply_const_vxx_1;
    blocks::multiply_const_ff::sptr blocks_multiply_const_vxx_0;
    blocks::float_to_complex::sptr blocks_float_to_complex_0;
    blocks::add_const_ff::sptr blocks_add_const_vxx_0;

// Parameters:
    double Ac = "1";
    double ka = "1";

// Variables:
    long samp_rate = 32000;

public:
    typedef std::shared_ptr<modulacionAM_1> sptr;
    static sptr make(double Ac, double ka);
    modulacionAM_1(double Ac, double ka);
    ~modulacionAM_1();

    double get_Ac () const;
    void set_Ac(double Ac);
    double get_ka () const;
    void set_ka(double ka);
    long get_samp_rate () const;
    void set_samp_rate(long samp_rate);

};






modulacionAM_1::modulacionAM_1 (double Ac, double ka) : hier_block2("Not titled yet",
                gr::io_signature::make(1, 1, sizeof(float)*1),
                gr::io_signature::make(1, 1, sizeof(gr_complex)*1)
        ) {


// Blocks:
    {
        this->blocks_null_source_0 = blocks::null_source::make(sizeof(float)*1);
    }
    {
        this->blocks_multiply_const_vxx_1 = blocks::multiply_const_cc::make(Ac);
    }
    {
        this->blocks_multiply_const_vxx_0 = blocks::multiply_const_ff::make(ka);
    }
    {
        this->blocks_float_to_complex_0 = blocks::float_to_complex::make(1);
    }
    {
        this->blocks_add_const_vxx_0 = blocks::add_const_ff::make(1);
    }

// Connections:
    hier_block2::connect(this->blocks_add_const_vxx_0, 0, this->blocks_float_to_complex_0, 0);
    hier_block2::connect(this->blocks_float_to_complex_0, 0, this->blocks_multiply_const_vxx_1, 0);
    hier_block2::connect(this->blocks_multiply_const_vxx_0, 0, this->blocks_add_const_vxx_0, 0);
    hier_block2::connect(this->blocks_multiply_const_vxx_1, 0, self(), 0);
    hier_block2::connect(this->blocks_null_source_0, 0, this->blocks_float_to_complex_0, 1);
    hier_block2::connect(self(), 0, this->blocks_multiply_const_vxx_0, 0);
}
modulacionAM_1::~modulacionAM_1 () {
}

// Callbacks:
double modulacionAM_1::get_Ac () const {
    return this->Ac;
}

void modulacionAM_1::set_Ac (double Ac) {
    this->Ac = Ac;
    this->blocks_multiply_const_vxx_1->set_k(this->Ac);
}

double modulacionAM_1::get_ka () const {
    return this->ka;
}

void modulacionAM_1::set_ka (double ka) {
    this->ka = ka;
    this->blocks_multiply_const_vxx_0->set_k(this->ka);
}

long modulacionAM_1::get_samp_rate () const {
    return this->samp_rate;
}

void modulacionAM_1::set_samp_rate (long samp_rate) {
    this->samp_rate = samp_rate;
}

modulacionAM_1::sptr
modulacionAM_1::make(double Ac, double ka)
{
    return gnuradio::make_block_sptr<modulacionAM_1>(
        Ac, ka);
}
#endif

