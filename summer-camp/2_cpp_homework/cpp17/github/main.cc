#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "queryresult.h"
#include "textquery.h"
#include "query_base.h"
#include "query.h"
#include "andquery.h"
#include "orquery.h"



int main()
{
    std::ifstream file("novel");

    TextQuery tQuery(file);

    Query q = Query("alice")  | Query("am");

    return 0;
}
