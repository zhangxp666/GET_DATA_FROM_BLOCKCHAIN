这是一个用于采集区块链系统中区块数据的系统，目前已支持比特币和以太坊。
本项目可在https://github.com/zhangxp666/GET_DATA_FROM_BLOCKCHAIN获取，

如何编译本系统，请按照以下步骤进行
1. 下载完整的代码包
2.	使用已安装MFC相关组件的VS2019（也许低版本没法打开解决方案，可考虑复制源码到自己的方案里）打开解决方案Research_Blockchain.sln。
3.	运行生成exe
4.	将lib文件下的libmysql.dll拷贝到生成exe的文件目录下

如何使用本系统，请按照以下步骤进行
1.	已得到编译好的exe
2.	配置好Mysql数据库，将sql文件下的数据库脚本放入数据库中生成表
3.	开启比特币或以太坊的节点，同步好数据后开启RPC服务
4.	将数据库和区块链节点的相关信息填入config.ini中
5.	运行程序

如何拓展本系统
1.	更多区块链系统和数据库的支持需要仿照现有的子类编写代码增加新的子类即可
2.	功能的提升需阅读代码后按需实现，代码中的注释还是比较清楚的。