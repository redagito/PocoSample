#include "foo/Foo.h"

#include <vector>

#include <Poco/Data/Session.h>
#include <Poco/Data/MySQL/Connector.h>

using namespace Poco::Data::Keywords;

Poco::DateTime foo::now()
{
    return Poco::DateTime{};
}

std::vector<std::string> foo::getNames(const std::set<int> ids)
{
    std::vector<std::string> names;

    try
    {
        Poco::Data::MySQL::Connector::registerConnector();
        // TODO Replace the connection string values for this to work
        Poco::Data::Session sess{"MySQL", "host=DB_HOST;db=DB_NAME;user=USER_NAME;password=USER_PASSWORD"};

        auto stmt = sess << "select pet_name from inventory where id in (?)";
        stmt, bind(ids);
        stmt, into(names), Poco::Data::Keywords::now;
    }
    catch (const Poco::Exception& e)
    {
        std::cout << e.displayText() << std::endl;
    }

    return names;
}