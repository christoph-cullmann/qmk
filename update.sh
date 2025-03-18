# update the modules
rm -rf modules/getreuer
git clone https://github.com/getreuer/qmk-modules.git modules/getreuer
rm -rf modules/getreuer/.git
git add modules/getreuer
