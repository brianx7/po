#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>

#include <gtest/gtest.h>

TEST(po_test, simple_test)
{
    EXPECT_EQ(1,1);
}
namespace po = boost::program_options;
void output_vm(po::variables_map const & vm)
{
    std::cout << vm["DefaultGroup"].as<std::string>() << std::endl;
}
TEST(po_test, empty_var)
{
    namespace po = boost::program_options;

    std::string fname = ".tmp.test.cnf";
    {
        std::ofstream tostr(fname.c_str(), std::ofstream::out | std::ofstream::trunc);
        tostr << "DefaultGroup = GROUP" << std::endl;
        tostr.close();
    }
    std::string cfg(fname);
    std::ifstream ifs(cfg.c_str());
    po::options_description cfgOptions("Cfg options");
    cfgOptions.add_options()
        ("help", "test")
        ("DefaultGroup", po::value<std::string>()->default_value(""), "Default group");
    po::variables_map vm;
    try
    {
        po::store(po::parse_config_file(ifs, cfgOptions), vm);
        po::notify(vm);
        output_vm(vm);
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
}
