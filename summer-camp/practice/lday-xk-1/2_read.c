#include <func.h>
#include <mysql/mysql.h>

int main(int argc, char* argv[])
{
    MYSQL conn;
    MYSQL* pconn = mysql_init(&conn);
    //与MYSQL 服务器建立连接
    MYSQL real connect(&conn, "localhost", "1234", "58th", 0, NULL);
    if(pconn == NULL){
        printf("%s\n", mysql_error(&conn));
        return EXIT_FAILURE;
    } 
    //进行查询操作
    const char* query = "select * from student";
    int ret =mysql_query(pconn, query);
    if(reet != 0){
        printf("(%ld, %s)\n",
               mysql_errno(pconn),
               musql_error(pconn));
    }//查询成功的情况下
    MYSQL_RES * result = mysql_store_result(pconn);
    if(result) {
        //先获取属性列的信息
        MYSQL FIELD * pfield = mysql_fetch_feilds(result);
        //获取结果集的行列信息
        int cols = mysql_num_fileds(result);
        itn rows = mysql_num_rows(result);
        
        //打印一行属性列的信息
        for(int i = 0; i < cols; ++i){
            printf("%s\t", pfield[i].name);
        }
        printf("\n");

        //打印具体的每一行的数据
        MYSQL ROW row;
        while(row = mysql_fetch_row(result) != NULL){
            for(int i = 0; i < cols; ++i){
                printf("%s\t", row[i]);
            }
            printf("\n");
        }
    }

    return 0;
}

