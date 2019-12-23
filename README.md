# 멀티캠퍼스 Linux class 시작

## 1일차 수업 환경설정 
- 리눅스 버전 : CentOS-7.0-1406-x86_64-DVD
- 영어 언어 추가, 표준 파티션에 새마운트 지점을 추가하였음. swap(하드디스크를 메모리처럼 사용) 지점에 2G, 마운트지점 /, 용량은 x

- 해당 과정에서는 실습을 위해서 관련 업데이트를 막았음.
- cd /etc/yum.repos.d/ 폴더에서 진행
- 아직 vim에 대해 배우지 않았으므로 gedit을 사용하였음
- gedit CentOS-Base. repo, gedit CentOS-Sources. repo에서 update파트 삭제
- CentOS-Base.repo의 백업파일을 만든 뒤  repo.~파일들을 삭제해 주었음.
- 이후 wget http://download.hanbit.co.kr/centos/7/CentOS-Base.repo로 파일설치.

- 파일권한을 644로 줌. 이후 yum clean all
