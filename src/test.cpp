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
TEST(po_test, no_var)
{
    namespace po = boost::program_options;

    std::string fname = ".tmp.test.cnf";
    {
        std::ofstream tostr(fname.c_str(), std::ofstream::out | std::ofstream::trunc);
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
        //        output_vm(vm);
        std::string str = vm["DefaultGroup"].as<std::string>();
        ASSERT_EQ(str, "");
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
}
TEST(po_test, group_var)
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
        //        output_vm(vm);
        std::string str = vm["DefaultGroup"].as<std::string>();
        ASSERT_EQ(str, "GROUP");
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
}
TEST(po_test, vigdataserver_file)
{
    namespace po = boost::program_options;

    std::string fname = "../VIGDataServerConfig.txt";
    std::string cfg(fname);
    std::ifstream ifs(cfg.c_str());
    po::options_description cfgOptions("Cfg options");
    cfgOptions.add_options()
        ("help", "config for client")
        ("DefaultGroup", po::value<std::string>()->default_value(std::string("")), "Name of tag messaging group used if not specified.")
        ("DefaultEnv",   po::value<std::string>()->default_value(""), "Name of tag messaging environment used if not specified.")
        ("DefaultOnRampAddr", po::value<std::string>()->default_value(""), "Name of tag messaging multicast env used if not specified.")
        ("DefaultNetwork", po::value<std::string>()->default_value(""), "Name of snapshot multicast addr used if not specified.")
        ("DefaultPrefix", po::value<std::string>()->default_value(""), "Name of snapshot prefix used to get symbol  id not specified.")

        ("SvrGroup"      , po::value<std::string>()->default_value("")             , "Name of tag messaging group server uses")
        ("SvrEnv"        , po::value<std::string>()->default_value("")             , "Name of tag messaging environment server uses")
        ("SvrSource"     , po::value<std::string>()->default_value("VIGDS.REQUEST") , "Name of tag messaging source that server uses")
        ("SvrOnRampAddr" , po::value<std::string>()->default_value("")             , "Name of tag messaging multicast addr server uses")
        
        ("CacheGroup", po::value<std::string>()->default_value(""), "Name of tag messaging group used to get VCloud caches")
        ("CacheEnv",   po::value<std::string>()->default_value(""), "Name of tag messaging environment used to get VCloud caches")
        ("CacheOnRampAddr", po::value<std::string>()->default_value(""),"Name of tag messaging multicast addr used to get VCloud caches")

        ("SnapshotGroup", po::value<std::string>()->default_value(""), "Name of tag messaging group used to get VCloud snapshots")
        ("SnapshotEnv",   po::value<std::string>()->default_value(""), "Name of tag messaging environment used to get VCloud snapshots")
        ("SnapshotOnRampAddr", po::value<std::string>()->default_value(""), "Name of tag messaging multicast env used to get VCloud snapshots")
        ("SnapshotNetwork", po::value<std::string>()->default_value(""), "Name of snapshot multicast addr used to get symbol data")
        ("SnapshotPrefix", po::value<std::string>()->default_value(""), "Name of snapshot prefix used to get symbol data")

        ("SymbologyGroup", po::value<std::string>()->default_value(""), "Name of symbology group used to get symbol data")
        ("SymbologyEnv", po::value<std::string>()->default_value(""), "Name of symbology environment used to get symbol data")
        ("SymbologyOnRampAddr", po::value<std::string>()->default_value(""), "Name of symbology multicast address used to get symbol data")
        ("SymbologyNetwork", po::value<std::string>()->default_value(""), "Name of symbology multicast addr used to get symbol data")
        ("SymbologyPrefix", po::value<std::string>()->default_value(""), "Name of symbology prefix used to get symbol data")

        ("PositionGroup", po::value<std::string>()->default_value(""), "Name of position group used to get position data")
        ("PositionEnv", po::value<std::string>()->default_value(""), "Name of position environment used to get position data")
        ("PositionOnRampAddr", po::value<std::string>()->default_value(""), "Name of position multicast address used to get position data")
        ("PositionNetwork", po::value<std::string>()->default_value(""), "Name of position multicast addr used to get position data")
        ("PositionPrefix", po::value<std::string>()->default_value(""), "Name of position prefix used to get position data")

        ("YieldGroup", "Name of yield group used to get yield data")
        ("YieldEnv", "Name of yield environment used to get yield data")
        ("YieldOnRampAddr", po::value<std::string>()->default_value(""), "Name of yield multicast address used to get yield data")
        ("YieldNetwork", po::value<std::string>()->default_value(""), "Name of yield multicast addr used to get yield data")
        ("YieldPrefix", po::value<std::string>()->default_value(""), "Name of yield prefix used to get yield data")

        ("PriceGroup", po::value<std::string>()->default_value(""), "Name of price group used to get price data")
        ("PriceEnv", po::value<std::string>()->default_value(""), "Name of price environment used to get price data")
        ("PriceOnRampAddr", po::value<std::string>()->default_value(""),"Name of price multicast address used to get price data")
        ("PriceNetwork", po::value<std::string>()->default_value(""), "Name of price multicast addr used to get price data")
        ("PricePrefix", po::value<std::string>()->default_value(""), "Name of price prefix used to get price data")

        ("LogLevel", po::value<std::string>()->default_value("INFO"),"Logging level (TRACE,DEBUG,INFO,WARN,ERROR)")
        ;
    po::variables_map vm;
    try
    {
        po::store(po::parse_config_file(ifs, cfgOptions), vm);
        po::notify(vm);
        //        output_vm(vm);
        std::string str = vm["DefaultGroup"].as<std::string>();
        ASSERT_EQ(str, "");
        str = vm["DefaultEnv"].as<std::string>();
        ASSERT_EQ(str, "");
        str = vm["DefaultOnRampAddr"].as<std::string>();
        ASSERT_EQ(str, "");
        str = vm["DefaultNetwork"].as<std::string>();
        ASSERT_EQ(str, "");
        str = vm["DefaultPrefix"].as<std::string>();
        ASSERT_EQ(str, "");
        str = vm["SvrGroup"].as<std::string>();
        ASSERT_EQ(str, "TAG");
        str = vm["SvrEnv"].as<std::string>();
        ASSERT_EQ(str, "Development");
        str = vm["SvrSource"].as<std::string>();
        ASSERT_EQ(str, "VIGDS.REQUEST");
        EXPECT_THROW(vm["JUNK"].as<std::string>(), boost::bad_any_cast);
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
}
