find . ! -path "./.git/*" -type f \( -name "*.cc" -o -name "*.cpp" -o -name "*.sample" -o -name "*.org" -o -name "*.java" -o -name "*.html" \) | while read LINE
do
    git add "${LINE}"
done
git add push.sh
git commit -m 'auto commit'
git push
